#include <iostream>
#include "lib.h"

int main() {
	cout << "Programm is running...\n";
	cout << description();
	cout << "Version 7\n";
	cout << "Simulation archive error:\n";
	Archive arch;
	arch.SetDataParts(arch.GetMaxDataParts());
	try {
		arch.create_part();
	}
	catch (NotEnoughSpaceInArchive& e) {
		cout << e.what();
	}
	system("pause");
}