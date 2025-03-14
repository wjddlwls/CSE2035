#include <iostream>
#include <cmath>
#include<cstdlib> //rand(), srand()
#include<ctime> //time()
#include <png.h>
using namespace std;
#define PNG_SETJMP_NOT_SUPPORTED

#define WIDTH 256
#define HEIGHT 256
#define COLOR_DEPTH 8

struct Pixel{
	png_byte r, g, b, a;
};
class Crd{//coordinate 입력받을 위치 미리 지정
public:
	int r;
	int c;
	Crd(){}
	Crd(int r,int c){
		this->r=r;
		this->c=c;
	}
};

class Color {
public:
    png_byte r, g, b, a;

    Color(png_byte red, png_byte green, png_byte blue, png_byte alpha = 255)
        : r(red), g(green), b(blue), a(alpha) {}

    void setColor(struct Pixel** row_pointers, int i, int j) const {
        row_pointers[i][j].r = r;
        row_pointers[i][j].g = g;
        row_pointers[i][j].b = b;
        row_pointers[i][j].a = a;
    }
};

void snow(struct Pixel** row_pointers, int cr, int cc, int s) {//2 4 4 2 
	int i=1;
	Color white(255,255,255);
	for(int row=cr;row<cr+2;row++){
		for(int col=cc-i;col<cc+i;col++){
			white.setColor(row_pointers, row, col);
		}
		i++;
	}
	for(int row=cr+2;row<cr+4;row++){
		i--;
		for(int col=cc-i;col<cc+i;col++){
			white.setColor(row_pointers, row, col);
		}
	}
}

void floorsnow(struct Pixel** row_pointers, int cr, int cc) {
	Color skyblue(204, 255, 255);
	Color blue(0, 130, 153);
	int p=2;
	for(int i=cr;i<(cr+10);i++){
		for(int j=(cc-p);j<=(cc+p);j++){
			skyblue.setColor(row_pointers, i, j);	
			if(i==cr+9){
				blue.setColor(row_pointers, i, j);
		}
		}
		if((i-cr)%2!=0){
			if((i-cr)<5){
				p+=3;
				continue;
			}
			p++;
		}
		
	}
}

void PinkBall(struct Pixel** row_pointers, int cr, int cc) {
	Color pink(255, 153, 153);
	Color black(0, 0, 0);
	Color white(255,255,255);
    for (int i = (cr - 10); i <= (cr + 10); i++) {
        for (int j = (cc - 10); j <= (cc + 10); j++) {
            if (pow((i - cr), 2) + pow((j - cc), 2) < pow(7, 2)){
                pink.setColor(row_pointers, i, j);

            }
            if (pow((i - cr), 2) + pow((j - cc), 2) == pow(7, 2)){
                black.setColor(row_pointers, i, j);
            }
            if ((i-cr)+(j-cc)==4&&(i-cr)>0&&(j-cc)>0){
                white.setColor(row_pointers, i, j);
            }
        }
    }
}

void BlueBall(struct Pixel** row_pointers, int cr, int cc) {
	Color blue(100, 233, 255);
	Color black(0, 0, 0);
	Color white(255,255,255);
    for (int i = (cr - 10); i <= (cr + 10); i++) {
        for (int j = (cc - 10); j <= (cc + 10); j++) {
            if (pow((i - cr), 2) + pow((j - cc), 2) < pow(7, 2)){
                blue.setColor(row_pointers, i, j);

            }
            if (pow((i - cr), 2) + pow((j - cc), 2) == pow(7, 2)){
                black.setColor(row_pointers, i, j);
            }
            if ((i-cr)+(j-cc)==4&&(i-cr)>0&&(j-cc)>0){
                white.setColor(row_pointers, i, j);
            }
        }
    }
}

void PurpleBall(struct Pixel** row_pointers, int cr, int cc) {
	Color purple(204, 204, 255);
	Color black(0, 0, 0);
	Color white(255,255,255);
    for (int i = (cr - 10); i <= (cr + 10); i++) {
        for (int j = (cc - 10); j <= (cc + 10); j++) {
            if (pow((i - cr), 2) + pow((j - cc), 2) < pow(7, 2)){
                purple.setColor(row_pointers, i, j);

            }
            if (pow((i - cr), 2) + pow((j - cc), 2) == pow(7, 2)){
                black.setColor(row_pointers, i, j);
            }
            if ((i-cr)+(j-cc)==4&&(i-cr)>0&&(j-cc)>0){
                white.setColor(row_pointers, i, j);
            }
        }
    }
}

void BlackGingerbread(struct Pixel** row_pointers, int cr, int cc){
    Color brown(184, 134, 11);
	Color black(0, 0, 0);
    Color red(255,0,0);
    Color yellow(255,255,51);
    for (int i = cr; i <= (cr + 7); i++) {
        for (int j = (cc - 2); j <= (cc + 2); j++) {
            brown.setColor(row_pointers, i, j);
        }
    } //몸통
    for (int j = (cc-3); j <= (cc-3); j++) {
        for (int i=(cr+1); i<=(cr+6); i++) {
            brown.setColor(row_pointers, i, j);
        }
    }   
    for (int j = (cc+3); j <= (cc+3); j++) {
        for (int i=(cr+1); i<=(cr+6); i++) {
            brown.setColor(row_pointers, i, j);
        }
    }   
    for (int j = (cc+4); j <= (cc+4); j++) {
        for (int i=(cr+2); i<=(cr+5); i++) {
            brown.setColor(row_pointers, i, j);
        }
    }
    for (int j = (cc-4); j <= (cc-4); j++) {
        for (int i=(cr+2); i<=(cr+5); i++) {
			brown.setColor(row_pointers, i, j);
        }
    } //머리
    for (int j = (cc-7); j <= (cc+7); j++) {
        for (int i=(cr+8); i<=(cr+11); i++) {
            brown.setColor(row_pointers, i, j);
    	}
	} //팔
    for (int j = (cc-5); j <= (cc-1); j++) {
        for (int i=(cr+12); i<=(cr+17); i++) {
            brown.setColor(row_pointers, i, j);
        }
    } 
    for (int j = (cc+1); j <= (cc+5); j++) {
        for (int i=(cr+12); i<=(cr+17); i++) {
            brown.setColor(row_pointers, i, j);
        }
    }//다리
    for (int i = (cr+18); i <= (cr+18); i++) {
        for (int j=(cc-4); j<=(cc-2); j++) {
            black.setColor(row_pointers, i, j);
        }
        for (int j=(cc+2); j<=(cc+4); j++) {
            black.setColor(row_pointers, i, j);
        }
    }//발
    for (int j = (cc-8); j <= (cc-8); j++) {
        for (int i=(cr+9); i<=(cr+10); i++) {
            black.setColor(row_pointers, i, j);
        }
    }
    for (int j = (cc+8); j <= (cc+8); j++) {
        for (int i=(cr+9); i<=(cr+10); i++) {
            black.setColor(row_pointers, i, j);
        }
    }//손
	
	black.setColor(row_pointers, cr+2, cc-1);
	black.setColor(row_pointers, cr+2, cc+1);//눈
    red.setColor(row_pointers, cr+8, cc);
    yellow.setColor(row_pointers, cr+10, cc);//단추


    for (int i = cr+5; i <= (cr + 5); i++) {
        for (int j = (cc - 2); j <= (cc + 2); j++) {
            black.setColor(row_pointers, i, j);
        }
    }//입
}

void WhiteGingerbread(struct Pixel** row_pointers, int cr, int cc){
    Color brown(184, 134, 11);
	Color white(255, 255, 255);
    Color red(255,0,0);
    Color yellow(255,255,51);
    for (int i = cr; i <= (cr + 7); i++) {
        for (int j = (cc - 2); j <= (cc + 2); j++) {
            brown.setColor(row_pointers, i, j);
        }
    } //몸통
    for (int j = (cc-3); j <= (cc-3); j++) {
        for (int i=(cr+1); i<=(cr+6); i++) {
            brown.setColor(row_pointers, i, j);
        }
    }   
    for (int j = (cc+3); j <= (cc+3); j++) {
        for (int i=(cr+1); i<=(cr+6); i++) {
            brown.setColor(row_pointers, i, j);
        }
    }   
    for (int j = (cc+4); j <= (cc+4); j++) {
        for (int i=(cr+2); i<=(cr+5); i++) {
            brown.setColor(row_pointers, i, j);
        }
    }
    for (int j = (cc-4); j <= (cc-4); j++) {
        for (int i=(cr+2); i<=(cr+5); i++) {
			brown.setColor(row_pointers, i, j);
        }
    } //머리
    for (int j = (cc-7); j <= (cc+7); j++) {
        for (int i=(cr+8); i<=(cr+11); i++) {
            brown.setColor(row_pointers, i, j);
    	}
	} //팔
    for (int j = (cc-5); j <= (cc-1); j++) {
        for (int i=(cr+12); i<=(cr+17); i++) {
            brown.setColor(row_pointers, i, j);
        }
    } 
    for (int j = (cc+1); j <= (cc+5); j++) {
        for (int i=(cr+12); i<=(cr+17); i++) {
            brown.setColor(row_pointers, i, j);
        }
    }//다리
    for (int i = (cr+18); i <= (cr+18); i++) {
        for (int j=(cc-4); j<=(cc-2); j++) {
            white.setColor(row_pointers, i, j);
        }
        for (int j=(cc+2); j<=(cc+4); j++) {
            white.setColor(row_pointers, i, j);
        }
    }//발
    for (int j = (cc-8); j <= (cc-8); j++) {
        for (int i=(cr+9); i<=(cr+10); i++) {
            white.setColor(row_pointers, i, j);
        }
    }
    for (int j = (cc+8); j <= (cc+8); j++) {
        for (int i=(cr+9); i<=(cr+10); i++) {
            white.setColor(row_pointers, i, j);
        }
    }//손
	
	white.setColor(row_pointers, cr+2, cc-1);
	white.setColor(row_pointers, cr+2, cc+1);//눈
    red.setColor(row_pointers, cr+8, cc);
    yellow.setColor(row_pointers, cr+10, cc);//단추

    for (int i = cr+5; i <= (cr + 5); i++) {
        for (int j = (cc - 2); j <= (cc + 2); j++) {
            white.setColor(row_pointers, i, j);
        }
    }//입
}

void Candycane(struct Pixel** row_pointers, int cr, int cc) {
	Color red(153, 51, 51);
	Color white(255, 255, 255);
    for (int j = (cc + 10); j >= (cc - 10); j--) {
        for (int i = (cr + 10); i >= (cr - 10); i--) {
            int x=j-cc;
            int y=i-cr;
            if (pow(x,2)+pow(y,2)>=pow(4,2)&&pow(x,2)+pow(y,2)<=pow(8,2)&&y<=0){
                white.setColor(row_pointers, i, j);
                if(y%3!=0){
                    red.setColor(row_pointers, i, j);
                }
        	}
    	}
    }
    for (int j = (cc + 10); j >= (cc - 10); j--){
        for (int i = (cr + 20); i >= (cr - 20); i--) {
            int x=j-cc;
            int y=i-cr;
            if(x>=4&&x<8&&y>0&&y<=15){
                white.setColor(row_pointers, i, j);
                if(y%3!=0){
                    red.setColor(row_pointers, i, j);
                }
            }
        }
    }
}


int main(int argc, char *argv[]) {
	srand(time(NULL));

	/* open PNG file for writing */
	FILE *f = fopen("out.png", "wb");
	if (!f) {
		fprintf(stderr, "could not open out.png\n");
		return 1;
	}

	/* initialize png data structures */
	png_structp png_ptr;
	png_infop info_ptr;

	png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (!png_ptr) {
		fprintf(stderr, "could not initialize png struct\n");
		return 1;
	}

	info_ptr = png_create_info_struct(png_ptr);
	if (!info_ptr) {
		png_destroy_write_struct(&png_ptr, (png_infopp)NULL);
		fclose(f);
		return 1;
	}

	/* begin writing PNG File */
	png_init_io(png_ptr, f);
	png_set_IHDR(png_ptr, info_ptr, WIDTH, HEIGHT, COLOR_DEPTH,
	             PNG_COLOR_TYPE_RGB_ALPHA, PNG_INTERLACE_NONE,
	             PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);
	png_write_info(png_ptr, info_ptr);

	/* allocate image data */
	struct Pixel *row_pointers[HEIGHT];
	for (int row = 0; row < HEIGHT; row++) {
		row_pointers[row] = (Pixel *)calloc(WIDTH*2, sizeof(struct Pixel));
	}


	int a = 40;//트리 위치 조절용(a 커질수록 아래로 감)
	Color white(255, 255, 255);


	/*배경 그리기*/


	//하늘

	Color skyblue(153, 204, 255);

	for(int row = 0; row < HEIGHT; row++){
		for(int col = 0; col < WIDTH; col++){
			skyblue.setColor(row_pointers, row, col);
		}
	}

	//눈보라

	srand((unsigned int)time(NULL));

	for(int i=0;i<20;i++){
		snow(row_pointers, rand()%240+10, rand()%240+10, 4);		
	}

	for(int i=20;i<250;i+=100){
		for(int j=20;j<200;j+=60){
			snow(row_pointers, j, i, 4);
		}
	}
	for(int i=70;i<250;i+=110){
		for(int j=30;j<200;j+=60){
			snow(row_pointers, j, i, 4);
		}
	}


	//눈 덮인 땅

	for(int row = HEIGHT*4/5; row < HEIGHT; row++){
		for(int col = 0; col < WIDTH; col++){
			white.setColor(row_pointers, row, col);
		}
	}


	//쌓인 눈 
	floorsnow(row_pointers,230,30);
	floorsnow(row_pointers,210,50);
	floorsnow(row_pointers,223,194);
	floorsnow(row_pointers,207,230);
	floorsnow(row_pointers,235,220);


	//트리 그림자

	Color gray(153, 153, 153);

	for(int row = HEIGHT*7/10; row < HEIGHT; row++){
		for(int col = 0; col < WIDTH; col++){
		if(pow(row-HEIGHT+25, 2)/164+pow(col-WIDTH/2, 2)/1818<1){
			gray.setColor(row_pointers, row, col);
			}
		}
	}


	/*트리 그리기*/

	Color green(20, 140, 20);
	Color deepgreen(20, 100, 20);

	for(int row = 0+a; row < HEIGHT/5+a; row++){//트리1
		int start=WIDTH/2-(row-a);
		int end=WIDTH/2+(row-a);
		for(int col = start; col < WIDTH/2; col++){
			deepgreen.setColor(row_pointers, row, col);
		}
		for(int col = WIDTH/2; col < end; col++){
			green.setColor(row_pointers, row, col);
		}
	}

	for(int row = HEIGHT/5+a; row < HEIGHT*2/5+a; row++){//트리2
		int start=WIDTH/2-(row-a)+20;
		int end=WIDTH/2+(row-a)-20;
		for(int col = start; col < WIDTH/2; col++){
			deepgreen.setColor(row_pointers, row, col);
		}
		for(int col = WIDTH/2; col < end; col++){
			green.setColor(row_pointers, row, col);
		}
	}

	for(int row = HEIGHT*2/5+a; row < HEIGHT*3/5+a; row++){//트리3
		int start=WIDTH/2-(row-a)+50;
		int end=WIDTH/2+(row-a)-50;
		for(int col = start; col < WIDTH/2; col++){
			deepgreen.setColor(row_pointers, row, col);
		}
		for(int col = WIDTH/2; col < end; col++){
			green.setColor(row_pointers, row, col);
		}
	}

	Color brown(140, 70, 20);
	Color deepbrown(120, 50, 10);

	for(int row = HEIGHT*3/5+a; row < HEIGHT-25; row++){//트리 밑동
		int start=WIDTH*2/5;
		int end=WIDTH*3/5;
		for(int col = start; col < end-20; col++){
			brown.setColor(row_pointers, row, col);
		}
		for(int col = end-20; col < end; col++){
			deepbrown.setColor(row_pointers, row, col);
		}
	}


	//별 장식

	Color yellow(255, 185, 51);

	for(int row = a*5/12; row < a*4/6; row++){//별 맨 위 삼각형
		int start=WIDTH/2-(row/2-a*4/18);
		int end=WIDTH/2+(row/2-a*4/18);
		for(int col = start-1; col <= end; col++){
			yellow.setColor(row_pointers, row, col);
		}
	}

	for(int row = a*4/6; row < a*5/6; row++){//별 중간 부분
		int start=WIDTH/2-(row*(-1)+a);
		int end=WIDTH/2+(row*(-1)+a);
		for(int col = start; col < end; col++){
			yellow.setColor(row_pointers, row, col);
		}
	}

	for(int row=a*5/6;row<a+10;row++){//별 다리1
		int start=WIDTH/2-(row/3-a/9);
		int end=WIDTH/2-(row*5/3-a*14/9);
		for(int col=start;col<end;col++){
			yellow.setColor(row_pointers, row, col); 
		}
	}

	for(int row=a*5/6;row<a+10;row++){//별 다리2
		int start=WIDTH/2+(row*5/3-a*14/9);
		int end=WIDTH/2+(row/3-a/9);
		for(int col=start;col<end;col++){
			yellow.setColor(row_pointers, row, col);
		}
	}


	//첫 번째 선 장식

	for(int j=3;j>0;j--){
		int start_r=HEIGHT/10+a-j;
		int start_c=WIDTH/2-HEIGHT/10;
		int end_r=HEIGHT/5+a-j;
		int end_c=WIDTH/2+HEIGHT/5;
		for(float i=0.0;i<1;i+=0.01){
        	int col = start_c + i * (end_c - start_c);
        	int row = start_r + i * (end_r - start_r);  
			Color darkeningryellow(255, 200+10*j, 60-10*j);
			darkeningryellow.setColor(row_pointers, row, col);
    	}
	}
	
	//두 번째 선 장식

	for(int j=3;j>0;j--){
		int start_r=HEIGHT*3/10+a-j;
		int start_c=WIDTH/2-HEIGHT*3/10+20;
		int end_r=HEIGHT*2/5+a-j;
		int end_c=WIDTH/2+HEIGHT*2/5-20;
		for(float i=0.0;i<1;i+=0.00001){
	        int col = start_c + i * (end_c - start_c);
    	    int row = start_r + i * (end_r - start_r);  
			Color darkeningryellow(255, 170+10*j, 90-10*j);
			darkeningryellow.setColor(row_pointers, row, col);
    	}
	}
	
	//세 번째 선 장식

	for(int j=3;j>0;j--){
		int start_r=HEIGHT/2+a-j;
		int start_c=WIDTH/2-HEIGHT/2+50;
		int end_r=HEIGHT*3/5+a-j;
		int end_c=WIDTH/2+HEIGHT*3/5-50;
		for(float i=0.0;i<1;i+=0.00001){
    	    int col = start_c + i * (end_c - start_c);
    	    int row = start_r + i * (end_r - start_r);
			Color darkeningryellow(255, 140+10*j, 120-10*j);
			darkeningryellow.setColor(row_pointers, row, col);
    	}
	}	


	//좌표 찾기용
	/*int row=HEIGHT*13/20;
	int col=WIDTH*14/20;
	row_pointers[row][col].r = 0;
    row_pointers[row][col].g = 0;
    row_pointers[row][col].b = 0;
    row_pointers[row][col].a = 255;
	*/


	//좌표 정해주기

	Crd crds[6]={};

	crds[0] = Crd(HEIGHT * 6 / 20, WIDTH * 11 / 20);
	crds[1] = Crd(HEIGHT * 8 / 20, WIDTH * 8 / 20);
	crds[2] = Crd(HEIGHT * 9 / 20, WIDTH * 12 / 20);
	crds[3] = Crd(HEIGHT * 13 / 20, WIDTH * 6 / 20);
	crds[4] = Crd(HEIGHT * 12 / 20, WIDTH * 10 / 20);
	crds[5] = Crd(HEIGHT * 13 / 20, WIDTH * 14 / 20);



	//출력

	cout << "\n당신의 크리스마스 트리를 꾸며주세요!\n" << endl;
	cout << "트리를 꾸밀 수 있는 다양한 오너먼트가 준비되어 있습니다. \n다음의 목록에서 총 여섯 개의 오너먼트를 골라 종류-색상 순으로 번호를 입력해주세요!\nex) pink ball을 원할 경우 : 11 입력" << endl;
	cout << "1. Ball - {1. pink, 2. blue, 3. purple}\n2. gingerbread - {1. black face, 2. white face}\n3. candycane - {1. red & white(one color)} " << endl;

	for(int i=0;i<6;i++){

		int num;
		cin >> num;
		cin.ignore();

		switch(num){
		case 11:
			PinkBall(row_pointers, crds[i].r, crds[i].c);
			break;
		case 12:
			BlueBall(row_pointers, crds[i].r, crds[i].c);
			break;
		case 13:
			PurpleBall(row_pointers, crds[i].r, crds[i].c);
			break;
		case 21:
			BlackGingerbread(row_pointers, crds[i].r, crds[i].c);
			break;
		case 22:
			WhiteGingerbread(row_pointers, crds[i].r, crds[i].c);
			break;
		case 31:
			Candycane(row_pointers, crds[i].r, crds[i].c);
			break;
		default:
			cout << "유효하지 않은 선택입니다. 1부터 6까지의 숫자 중 하나를 입력하세요." << endl;
        	i--;
			break;
		}
	}



	/* write image data to disk */
	png_write_image(png_ptr, (png_byte **)row_pointers);

	/* finish writing PNG file */
	png_write_end(png_ptr, NULL);

	/* clean up PNG-related data structures */
	png_destroy_write_struct(&png_ptr, &info_ptr);

	/* close the file */
	fclose(f);
	f = NULL;

	return 0;
}
