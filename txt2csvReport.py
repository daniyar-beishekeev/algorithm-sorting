import csv
import parser

with open('report.txt', 'r') as f:
	data = parser.txt2csv(f.read())

	with open('report.csv', mode="w", newline="") as file:
		writer = csv.DictWriter(file, fieldnames=data[0].keys())
		writer.writeheader()
		writer.writerows(data)