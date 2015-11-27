
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

bool intPairCompare(std::pair<int,int> aLeftPair, std::pair<int,int> aRightPair) {
	bool result = false;
	if(aLeftPair.second > aRightPair.second) {
		result = true;
	} else if ((aLeftPair.second == aRightPair.second) && (aLeftPair.first < aRightPair.first)) {
		result = true;
	}
	return result;
}

void printNumberCount(const std::vector<int>& anIntVector) {
	//count each number using a map 
	std::map<int,int> intCountMap;
	for(std::vector<int>::const_iterator ii = anIntVector.begin() ; ii != anIntVector.end() ; ++ii) {
		std::map<int,int>::const_iterator existingLocation = intCountMap.find(*ii);
		if(intCountMap.end() == existingLocation) {
			intCountMap[*ii] = 1;
		} else {
			intCountMap[*ii] = 1 + intCountMap[*ii];
		}
	}
	// sort each <number, count> pair by count then by number
	bool(*compareFunctionPointer)(std::pair<int,int>,std::pair<int,int>) = intPairCompare;
	std::vector<std::pair<int,int>> intCountVector(intCountMap.begin(), intCountMap.end());
	std::sort<std::vector<std::pair<int,int>>::iterator, bool(*)(std::pair<int,int>,std::pair<int,int>)> (intCountVector.begin(), intCountVector.end(), intPairCompare);
	//output the sorted data
	for(std::vector<std::pair<int,int>>::const_iterator jj = intCountVector.begin() ; jj != intCountVector.end() ; ++jj) {
		std::cout << jj->first << " : " << jj->second << std::endl;
	}
}
