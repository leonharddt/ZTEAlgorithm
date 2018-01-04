#pragma once
#include <vector>

namespace ZTE_crb {
	enum class VexType : int{ START, END, COMMON, MUST, FORBIT };
	enum class EdgeType : int { COMMON, MUST, FORBIT };
	
	using Vex = int;
	using Path = std::vector<Vex>;
	using Edge = std::pair<Vex, Vex>;
	using Matrix = std::vector<Path>;

	const int MAX_VEX = 1000;
	const int MAX_EDGE = 1000;
	const int MAX_DIS = 1000;
}