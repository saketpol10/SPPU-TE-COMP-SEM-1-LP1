#include <iostream>
using namespace std;
class spos {
int num;
string process[10];
int AT[10];
int BT[10];
int CT[10];
int TAT[10];
int WT[10];
public:
spos(int n) {
num = n;
}
void Input() {
for (int i = 0; i < num; i++) {
cout << "Process_no.: P" << (i + 1) << endl;
process[i] = "P" + to_string(i + 1);
cout << "AT: ";
cin >> AT[i];
cout << "BT: ";
cin >> BT[i];
}
}
void sort() {
int n = num;
string temp2;
int temp, temp1;
bool swapped;
for (int i = 0; i < n - 1; i++) {
swapped = false;
for (int j = 0; j < n - i - 1; j++) {
if (AT[j] > AT[j + 1]) {
// Swap AT[j] and AT[j+1]
temp = AT[j];
AT[j] = AT[j + 1];
AT[j + 1] = temp;
// Swap BT[j] and BT[j+1]
temp1 = BT[j];
BT[j] = BT[j + 1];
BT[j + 1] = temp1;

// Swap process[j] and process[j+1]
temp2 = process[j];
process[j] = process[j + 1];
process[j + 1] = temp2;
swapped = true;
}
}
// If no two elements were swapped by inner loop, then break
if (!swapped)
break;
}
}
float* calc() {
if (AT[0] == 0) {
CT[0] = BT[0] - AT[0];
for (int i = 0; i < num; i++) {
CT[i + 1] = BT[i + 1] + CT[i];
TAT[i] = CT[i] - AT[i];
WT[i] = TAT[i] - BT[i];
}
}
else {
CT[0] = BT[0] - AT[0];
for (int i = 0; i < num; i++) {
CT[i] = BT[i] + AT[i];
TAT[i] = CT[i] - AT[i];
WT[i] = TAT[i] - BT[i];
}
}
float* TATWT = new float[2]{ 0.0, 0.0 };
for (int i = 0; i < num; i++) {
TATWT[0] += TAT[i];
TATWT[1] += WT[i];
}
TATWT[0] /= num;
TATWT[1] /= num;
return TATWT;
}
void print() {
float* a = calc();
cout << "\nProcess No.\t\tAT\t\t\t BT\t\t\t CT\t\t\t TAT\t\t WT" << endl;
for (int i = 0; i < num; i++) {
cout << process[i] << "\t\t\t\t" << AT[i] << "\t\t\t" << BT[i] << "\t\t\t" << CT[i] << "\t\t\t "
<< TAT[i] << "\t\t\t" << WT[i] << endl;
}
cout << "\nAverage TAT: " << a[0] << "\t Average WT: " << a[1] << endl;
}

};
int main() {
cout << "Enter the number of processes: ";
int n;
cin >> n;
spos obj(n);
obj.Input();
obj.sort();
obj.print();
return 0;
}
