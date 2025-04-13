template<typename T>
class stack{
private:
	struct node{
		node *prev;
		T value;
	};
	node* topElement;
public:
	stack(): topElement(nullptr){}
	void push(T elem){
		node *newNode = new node();
		newNode->prev = topElement;
		newNode->value = elem;

		topElement = newNode;
	}
	void pop(){
		node *newRoot = topElement->prev;
		delete topElement;
		topElement = newRoot;
	}
	bool empty(){
		return topElement == nullptr;
	}
	T top(){
		return topElement->value;
	}
};