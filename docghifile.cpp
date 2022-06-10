//============== BT lý thuyết ==============
//1. trình bày đường dẫn tương đối, và đường dẫn tuyệt đối.
// 
// Đường dẫn tương đối là đường dẫn vào folder của ổ cứng của người lập trình và chỉ người lập trình đó dùng được 
// nhưng đường dẫn tuyệt đối lại ngược lại nó chỉ đến tên file cần mở và file đó được nén lại gửi cho các người lập trình khác
// và ai cũng có thể dùng được 
// 
//2. Nhận xét Đúng SAi :
//a) Đọc file sau khi được đóng file, thì lần đọc file sau con trỏ sẽ trỏ về đầu
// - a) Đúng ;
// - b) Sai
// 
//b) Ghi file sau khi được đóng file, thì kết quả ghi file lần sau sẽ ghi tiếp vào file kết quả
// 
// (tên hàm ) .eof() đây là câu lệnh bằng true khi con trỏ nằm ở cuối file 
// + false khi khoongg ở cuối file
// 
// +( ten hàm ) .fail() hàm kiểm tra xem file mở được không bằng true là k mở được ;
//
//
//+ (tên hàm). seekg (x,y);
// x: là số đơn vị muốn dịch (trái hoặc phải ) phải + , trái - 
// y : vị trí bắt đầu dịch : 0 (beg) , 1(cur) 2 (endl) // 
// 
//



///////////=================BAI TAP================================

#include <iostream>
#include <fstream>
using namespace std;
void xuat(int a[], int n);
int bcnn(int a[], int n);
int min(int a[], int n);
void lv1(int a[], int &n);
int max(int a[], int n);
bool amstrong(int so);
void lv2(int a[], int& n); 
void lv3(int a[], int& n);
int ucln(int a[], int n);
int main ()
{
	int a[100];
	int n = 0;
	//lv1(a, n);
	//cout << "==========lv1=======" << endl;
	//xuat(a, n);
	//cout << "Max la : " << max(a, n) << endl;
	//lv2(a, n);
	//xuat(a, n);
	lv3(a, n);
	xuat(a, n);
	system("pause");
	return 0;
}
void lv1(int a[], int &n)
{
	// Cấu trúc file 
	// 
	// 5 (n số cần lưu vào mảng )
	// 1 2 3 4 5 (số lưu vào mảng)
	//
	ifstream file;
	// khai báo một biến file name is file;
	
	file.open("input.txt", ios_base::in);
	// mở file lên và chỉ cho phép đọc
	if (file.fail() == true) // hàm trả về true nếu k mở được file 
	{
		cout << "Error" << endl;
	}
	file >> n;
	for (int i = 0; i < n; i++)
	{
		file >> a[i];
	}
	file.close();

	// =============Ghi file ==================
	int Max = max(a, n);
	ofstream outfile;
	outfile.open("output.txt", ios :: out);
	outfile << Max << endl;
}
int max(int a[], int n)
{
	int max = a[0];
	for(int i = 1; i < n; i++)
	{
		if (max < a[i])
		{
			max = a[i];
		}
	}
	return max;
}

int min(int a[], int n)
{
	int min = a[0];
	for (int i = 1; i < n; i++)
	{
		if (min > a[i])
		{
			min = a[i];
		}
	}
	return min;
}

void lv2(int a[], int &n)
{
	// Cấu trúc file 
	// 
	// biết: chỉ có 1 dòng duy nhất chứa các số nguyên
		/*VD: input.txt
		12 345 1 7 12 1*/
	//
	ifstream file;
	// khai báo một biến file name is file;

	file.open("inputlv2.txt", ios_base::in);
	// mở file lên và chỉ cho phép đọc
	if (file.fail() == true) // hàm trả về true nếu k mở được file 
	{
		cout << "Error" << endl;
	}
	n = 0;
	while (file.eof() == false)// hàm trả về true khi nằm ở cuối file và ngược lại 
	{
		file >> a[n++];
	}
	file.close();

	// =============Ghi file ==================
	int Max = max(a, n);
	ofstream outfile;
	outfile.open("outputlv2.txt", ios::out);
	bool kiemtra = false;
	for (int i = 0; i < n; i++)
	{
		kiemtra = amstrong(a[i]);
		if (kiemtra == true)
		{
			outfile << a[i] << ' ';
		}
	}
	outfile.close();
}
void lv3(int a[], int& n)
{
	// Cấu trúc file 
	// 
	// biết: chỉ có 1 dòng duy nhất chứa các số nguyên và xen kẽ dâu phẩy dấu chấm
		/*VD: input.txt
		1.2.3,4,5h6								*/
		//
	ifstream file;
	// khai báo một biến file name is file;

	file.open("inputlv3.txt", ios_base::in);
	// mở file lên và chỉ cho phép đọc
	if (file.fail() == true) // hàm trả về true nếu k mở được file 
	{
		cout << "Error" << endl;
	}
	n = 0;
	while (file.eof() == false)// hàm trả về true khi nằm ở cuối file và ngược lại 
	{
		file >> a[n++];
		file.ignore(); // bỏ qua một kí tự của file chuyển sang kí tự tiếp theo;
	}
	file.close();

	// =============Ghi file ==================
	int Max = max(a, n);
	ofstream outfile;
	outfile.open("outputlv3.txt", ios::out);
	int Ucln = ucln(a, n);
	outfile << "Ucln:" << Ucln << endl;
	int Bcnn = bcnn(a,n);
	outfile << "Bcnn:" << Bcnn << endl;
	outfile.close();
}
int ucln(int a[], int n)
{
	int Min = min(a, n);
	int temp = 0;
	for (int i = Min; i > 0; i--)
	{
		for (int j = 0; j < n; j++)
		{
			// kiểm tra ucln trong mảng có chia được heetst không
			if (a[j] % i != 0)
			{
				break;
			}
			else
			{
				temp++;
			}
		}
		// kiểm tra xem có phải ucln không nếu có thì trả về
		if (temp == n)
		{
			return i;
		}
		else
		{
			temp = 0;
		}
	}
}
int bcnn(int a[], int n)
{
	int Max = max(a, n);
	bool kt;
	for (int i = Max; i < Max * 2; i++)
	{
		for (int j = 0; j< n; j++)
		{
			if (i % a[j] == 0)
			{
				kt = true;
			}
			else
			{
				kt =false; 
				break;
			}
		}
		if (kt == true)
		{
			return i;
		}
	}
}
bool amstrong(int so)
{
	// ta truyền vào số 153 trước tiên cần đếm xem nó có bn số
	int  temp = so;
	int tong = 0;
	int dem = 0;
	// đếm bao nhiêu số
	while (temp != 0)
	{
		temp = temp / 10;
		dem++;
	}temp = so;
	do
	{
		tong = tong + pow((temp % 10), dem);
		temp = temp / 10;
	} while (temp != 0);
	if (tong == so)
	{
		return true; // trả về true nếu là ams
	}
	else
	{
		return false; // ngược lại 
	}
}
void xuat(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << endl;
	}
}
