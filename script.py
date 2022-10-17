import time
import os
import subprocess
import timeit


def readTextFile(filePath):
    with open(filePath, 'r') as f:
        print(f.name)


listFilePath = []
listFileNameWithEnd = []
listFileName = []
path = "/home/lelouvincx/Documents/code/TH_CTDLGT/CTDL-GT-_-Do-an-tuan-3-5/Code"
os.chdir(path)
# iterate through all file
for file in os.listdir():
    if file.endswith('.cpp'):
        filePath = f"{path}/{file}"
        listFilePath.append(filePath)
        fileNameWithEnd = f"{file}"
        listFileNameWithEnd.append(fileNameWithEnd)
        fileName = fileNameWithEnd[:-4]
        listFileName.append(fileName)


listTestPath = []
listTestNameWithEnd = []
listTestName = []
path = "/home/lelouvincx/Documents/code/TH_CTDLGT/CTDL-GT-_-Do-an-tuan-3-5/Tests"
os.chdir(path)
for file in os.listdir():
    if file.endswith('.txt'):
        testPath = f"{path}/{file}"
        listTestPath.append(testPath)
        testNameWithEnd = f"{file}"
        listTestNameWithEnd.append(testNameWithEnd)
        testName = testNameWithEnd[:-4]
        listTestName.append(testName)


path = "/home/lelouvincx/Documents/code/TH_CTDLGT/CTDL-GT-_-Do-an-tuan-3-5/Results"
os.chdir(path)
for i in range(len(listFilePath)):
    code = listFilePath[i]
    print('Compiling', listFileName[i])
    subprocess.Popen(['g++', code, '-o', 'a'])
    time.sleep(2)
    for j in range(len(listTestPath)):
        test = listTestPath[j]
        result = listFileName[i] + '_' + listTestName[j] + '.txt'
        print('Running', listTestName[j], 'in', listFileName[i])
        start = timeit.default_timer()
        os.system('./a < ' + test + ' > ' + result)
        stop = timeit.default_timer()
        print('Time consumed', stop - start)
        timeConsumed = stop - start
        time.sleep(1)
