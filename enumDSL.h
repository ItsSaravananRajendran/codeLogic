#include "dsl.h"

class enum vectorToInt {
	head,
	tail,
	minimum,
	maximum,
	sum,
	access
};

class enum vectorToVector {
	take,
	drop,
	sorted,
	reversed
};

class enum intToInt {
	incr,
	decr,
	square,
	multiply2,
	multiply3,
	multiply4,
	half,
	onethird,
	onefourth,
	invert
};

class enum intToBool{
	pos,
	neg,
	even,
	odd
};

class enum intPairToInt{
	addTwo,
	subTwo,
	mulTwo,
	divTwo
};

class enum higher{
	zipwith,
	scanl
}