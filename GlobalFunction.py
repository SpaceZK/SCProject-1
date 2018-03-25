def fCuttingListProcess(dataList, lenOffset):
	newList = []
	for len in dataList:
		newList.append(len + lenOffset)
	return newList

def fTotalLengthProcess(totalLength, lenOffset):
	return totalLength + lenOffset

def fCalculateCuttingResult(totalLength, cuttingList):
	result = []
	for item in cuttingList:
		for i in range(1, totalLength):
			if(i >= item):
				if(result[i])

fCalculateCuttingResult(10, [])


