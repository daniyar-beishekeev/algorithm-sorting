#include <cstdlib>
#include "../utils/stack.cpp"

template<typename T>
class segmentTree;

class tournamentSort{
public:
	template<typename T>
	//Left iterator, Right iterator, *swap function, *comparator function
	static void sort(T *l, T *r, bool (&cmp)(T&, T&), void(&swp)(T&, T&)){
		//Assume range is valid address
		//assert(l <= r);
		
		sort_runner(l, r, cmp, swp);
		return;
	}
private:
	template<typename T>
	//le -> less than comparator
	static inline void sort_runner(T *&l, T *&r, bool (&le)(T&, T&), void(&swp)(T&, T&)){
		segmentTree<T> minHeap(l, r, le);
		size_t n = r - l;
		
		T* extraSpace = new T[n];
		T* cur = extraSpace;
		T* cur2;

		for(size_t i = 0; i < n; i++, cur++)
			swp(*minHeap.popRoot(), *cur);

		cur = extraSpace;
		cur2 = l;
		for(size_t i = 0; i < n; i++, cur++, cur2++)
			swp(*cur2, *cur);
		return;
	}
};

//Minized segmentTree with build, get root, clear root
//More like binary tree
template<typename T>
class segmentTree{
private:
	struct node{
		node* lson;
		node* rson;
		T* value;
		node(): lson(nullptr), rson(nullptr), value(nullptr){}
	};
	bool (*cmp)(T&, T&);
	node* root;

	inline T* combine(node* &l, node* &r){
		if(l == nullptr and r == nullptr)
			return nullptr;
		if(l == nullptr)
			return r->value;
		if(r == nullptr)
			return l->value;
		if(cmp(*(l->value), *(r->value)))
			return l->value;
		else
			return r->value;
	}

	void build(node *v, T *l, T *r){
		if(l == r){
			v->value = l;
		}else{
			T* mid = l + (r - l) / 2;
			v->lson = new node();
			v->rson = new node();
			build(v->lson, l, mid);
			build(v->rson, mid + 1, r);
			v->value = combine(v->lson, v->rson);
		}
	}

	inline node* otherSon(node *&v, node *&cur){
		if(v->lson == cur)
			return v->rson;
		else
			return v->lson;
	}

	inline void updateMySon(node *&v, node *&cur, node *value){
		if(v->lson == cur)
			v->lson = value;
		else
			v->rson = value;
	}

public:

	segmentTree(T* &l, T* &r, bool (&le)(T&, T&)): cmp(le), root(new node()){
		build(root, l ,r - 1);
	}
	T* popRoot(){
//		assert(root != nullptr);
		T* ans = root->value;

		//Road to ans
		node *v = root;
		node *par = nullptr;
		node *par2 = nullptr;
//		std::stack<node*>backtrace;
		stack<node*>backtrace;
		while(v->lson != nullptr /*v->rson != nullptr*/){
			backtrace.push(v);
			par2 = par;
			par = v;
			if(v->lson->value == ans)
				v = v->lson;
			else
				v = v->rson;
			
		}

		if(par == nullptr){
			//Only root
			delete root;
			root = nullptr;
		}else{
			backtrace.pop();
			if(par2 == nullptr){
				//Roots son
				root = otherSon(par, v);
				delete v;
				delete par;
			}else{
				updateMySon(par2, par, otherSon(par, v));
				delete v;
				delete par;
			}
			while(!backtrace.empty()){
				node *v = backtrace.top();
				backtrace.pop();
				v->value = combine(v->lson, v->rson);
			}
		}

		return ans;
	}

	~segmentTree(){
		delete root;
	}
};