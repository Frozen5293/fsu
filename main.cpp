#include "RunAs.hpp"

using namespace std;


int main(int n, char** parms) {
	
	auto p= Command::Command(n, parms);
	RunAs::Run(p);
	
	return 1;
}




