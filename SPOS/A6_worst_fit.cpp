#include <iostream>
using namespace std;
int main()
{
 int fragment[20], b[20], p[20], i, j, nb, np, temp, largest = -1;
 static int barray[20], parray[20];
 cout << "Enter the number of blocks:";
 cin >> nb;
 cout << "Enter the number of processes:";
 cin >> np;
 cout << "Enter the size of the blocks:-\n";
 for (i = 1; i <= nb; i++)
 {
 cout << "Block no." << i << ":";
 cin >> b[i];
 }
 cout << "Enter the size of the processes :-\n";
 for (i = 1; i <= np; i++)
 {
 cout << "Process no. " << i << ":";
 cin >> p[i];
 }
 for (i = 1; i <= np; i++)
 {
 for (j = 1; j <= nb; j++)
 {
 if (barray[j] != 1)
 {
 if (b[j] >= p[i])
 {
 if (largest == -1 || b[largest] < b[j])
 {
 largest = j;
 }
 }
 }
 }
 fragment[i] = b[largest] - p[i];
 parray[i] = largest;
 barray[largest] = 1;
 largest = -1;
 }
 cout << "\nProcess_no\tProcess_size\tBlock_no\tBlock_size\tFragment";
 for (i = 1; i <= np && parray[i] != 0; i++)
 cout << "\n\t" << i << "\t\t\t" << p[i] << "\t\t\t" << parray[i] << "\t\t\t" << b[parray[i]] << "\t\t\t"
<< fragment[i];
 return 0;
}