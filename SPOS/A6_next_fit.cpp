#include <iostream>
using namespace std;
int main() {
 int b[20], p[20], i, j, nb, np;
 static int barray[20], parray[20];
 int last =1;

 cout << "\nEnter the number of blocks:";
 cin >> nb;
 cout << "Enter the number of processes:";
 cin >> np;
 cout << "\nEnter the size of the blocks:-\n";
 for (i = 1; i <= nb; i++) {
 cout << "Block no." << i << ":";
 cin >> b[i];
 }
 cout << "\nEnter the size of the processes :-\n";
 for (i = 1; i <= np; i++) {
 cout << "Process no. " << i << ":";
 cin >> p[i];
 }
 for (i = 1; i <= np; i++) {
 for (j = last; j <= nb; j++) {
 if (barray[j] != 1) {
 if (b[j] >= p[i]) {
 parray[i] = j;
 b[j] -= p[i];
 barray[j] = 1;
 last =j % nb+1;
 break;
 }
 }
 }
 }
 cout << "\nProcess_no\tProcess_size\tBlock_no";
 for (i = 1; i <= np; i++) {
 if (parray[i] != 0) {
 cout << "\n\t" << i << "\t\t\t\t" << p[i] << "\t\t\t\t" << parray[i];
 }
 }
 return 0;
}