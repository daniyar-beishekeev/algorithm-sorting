def txt2csv(content):
	report = content.strip('\n\n').split('\n\n')
	data = []
	for i in report:
		content = {}
		for j in i.split('\n'):
			j = j.split(':')
			j[0] = j[0].strip()
			j[1] = j[1].strip()
			content[j[0]] = j[1]
		data.append(content)
	return data