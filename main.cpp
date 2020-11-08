#include<iostream>
#include<fstream>
using namespace std;

//Variable declaration
int bmp_w;
int bmp_h;
char bmp_ASCII[500][500];
int i = 0, j = 0;
double max_grayScale = (0.3*(255.0) + 0.59*(255.0) + 0.11*(255.0));

//Function intialization
void print_bmp();
int get_rgbLength(int width);
void setArray(double gray_scale);

int main(){
	char bmp[20];
	cin >> bmp;
	cout << endl;
	ifstream fin;
	fin.open(bmp);
	unsigned char* bmp_info;
	
  bmp_info = new unsigned char[54];
	fin.read((char*)bmp_info, 54);
	bmp_w = *(int*)&bmp_info[18];
	bmp_h = *(int*)&bmp_info[22];

	int rgbLength = bmp_w * 3;
	unsigned char* pixelInfo = new unsigned char[rgbLength];
	char temp;
  double avg = 0;

	while (i < bmp_h)
	{
		fin.read((char*)pixelInfo, rgbLength);
  
		for (j = 0; j < bmp_w * 3; j += 3)
		{
			double grayScale = (0.3*((int)pixelInfo[j]) + 0.59*((int)pixelInfo[j + 1]) + 0.11*((int)pixelInfo[j + 2]));
      bmp_ASCII[i][j] = grayScale;
			setArray(grayScale);
		}
		i++;
	}
  
	fin.close();
	print_bmp();
}


//Functions

void setArray(double gray_scale){
  double conversionRate = 127 / max_grayScale;
  int asciiVal = conversionRate * gray_scale;
  if(asciiVal > 126) {
    asciiVal = 126;
  }
  if(asciiVal < 33) {
    asciiVal = 32;
  }
  bmp_ASCII[i][j] = asciiVal;
  
}

void print_bmp() {
	for (int i = bmp_h - 1; i >= 0; i--){
		for (int j = 0; j < bmp_w * 3; j = j + 3){
			cout << bmp_ASCII[i][j];
    }
		cout << endl;
  }
}