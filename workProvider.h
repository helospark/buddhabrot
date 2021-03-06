#ifndef WORKPROVIDER_H
#define WORKPROVIDER_H
#include <mutex>
#include "fractalParams.h"

struct WorkUnit {
	unsigned int index;
	long long iterationLimit;
	long long iterationCount;
	long long minIterationCount;
	double power;
	bool saveTemporaryResult = true;
};

class WorkProvider {
	std::mutex workUnitAccessMutex;
	int numberOfWorkUnits;
	int currentWorkUnitIndex;
	WorkUnit** workUnits;
	public:
		WorkProvider(FractalParams& params, unsigned int colorStepIndex, long long workUnitSize, double power, bool saveTemporaryResult);
		~WorkProvider();
		
		WorkUnit* getWorkUnit();
};

#endif