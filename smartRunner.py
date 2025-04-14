from collections import defaultdict
import parser

reportFile = 'report.txt'

# REQUIRES TEST FORMAT 
# level<LEVEL>_n<N>_<TESTNAME>_v<TESTNUM>

import os
import subprocess

folder_path = 'tests'
subprocess.run(f'> "{reportFile}"', shell = True)

testTypes = defaultdict(list)

for filename in os.listdir(folder_path):
	file_path = os.path.join(folder_path, filename)
	if os.path.isfile(file_path):
		lvl, n, tp, v = filename.split('_')
		testTypes[tp].append((lvl, filename))
		# subprocess.run(cmd, shell = True)

for CYCLE_ID in range(1, 11):
	print('Running cycle:', CYCLE_ID)
	for tp in testTypes:
		print('Testing:', tp)
		SUFF = ''
		subtasks = sorted(list(set([(int(''.join(filter(str.isdigit, _[0]))), _[0]) for _ in testTypes[tp]])))
		for order, subtask in subtasks:
			print('Subtask', subtask, 'allowed', SUFF)
			tests = list(filter(lambda x: x[0] == subtask, testTypes[tp]))
			toRun = set()
			for lvl, test in tests:
				file_path = os.path.join(folder_path, test)
				cmd = f'./main test "{file_path}" "Run,{CYCLE_ID}<-${file_path}" {SUFF}> smartRunner.tmp'
				subprocess.run(cmd, shell = True)
				subprocess.run(f'cat smartRunner.tmp >> {reportFile}', shell = True)

				f = open('smartRunner.tmp', 'r')
				content = f.read()
				content = parser.txt2csv(content)
				for res in content:
					if res['Result'] == 'Success':
						#Allow run process if only it passes previous test
						toRun.add(res['Algorithm'])

				f.close()
			SUFF = ','.join(toRun) + ' '
				
subprocess.run(f'rm smartRunner.tmp', shell = True)