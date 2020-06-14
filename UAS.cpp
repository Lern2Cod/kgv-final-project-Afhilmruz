#include <GL/glut.h>
#include<iostream>
#include<math.h>


using namespace std;

//Variabel untuk layar
int lLayar = 400, tLayar = 400;
int xPos = 10, yPos = 10;
float orthoXMin = -400;
float orthoXMax = 400;
float orthoYMin = -400;
float orthoYMax = 400;
float orthoZMin = -400;
float orthoZMax = 400;

void aturWindows() {
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(lLayar, tLayar);
    glutInitWindowPosition(xPos, yPos);
    glutCreateWindow("ULAR BALAP");
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glOrtho(orthoXMin, orthoXMax, orthoYMin, orthoYMax, orthoZMin, orthoZMax);
}

//Variabel penglihatan
float phiNow = 0, longest = 20, phi = 22 / 7;
float eyeX = 0, eyeY = 20, eyeZ = -20;

void CameraView() {
    eyeZ = (0 - 1) * longest * cos(phiNow / 100);
    eyeX = longest * sin(phiNow / 100);
    cout << eyeX << " ||| " << eyeY << " ||| " << eyeZ << endl;
    gluLookAt(eyeX, eyeY, eyeZ, 0, 0, 0, 0, 1, 0);
}

void buatKubus(float xAwal, float yAwal, float zAwal, float panjangRusuk) {
    //Atas
    glBegin(GL_QUADS);
    glColor3f(1, 0.8, 0.8);
    glVertex3f(xAwal, yAwal, zAwal);
    glColor3f(1, 0.5, 0.8);
    glVertex3f(xAwal + panjangRusuk, yAwal, zAwal);
    glColor3f(1, 0.5, 0.8);
    glVertex3f(xAwal + panjangRusuk, yAwal, zAwal + panjangRusuk);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(xAwal, yAwal, zAwal + panjangRusuk);
    glEnd();
    //Bawah
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.5, 0);
    glVertex3f(xAwal, yAwal - panjangRusuk, zAwal);
    glColor3f(0.7, 0.6, 0);
    glVertex3f(xAwal + panjangRusuk, yAwal - panjangRusuk, zAwal);
    glColor3f(0.8, 0.5, 0);
    glVertex3f(xAwal + panjangRusuk, yAwal - panjangRusuk, zAwal + panjangRusuk);
    glColor3f(0.7, 0.4, 0);
    glVertex3f(xAwal, yAwal - panjangRusuk, zAwal + panjangRusuk);
    glEnd();
    //Kiri
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.5, 0);
    glVertex3f(xAwal, yAwal, zAwal);
    glVertex3f(xAwal, yAwal - panjangRusuk, zAwal);
    glVertex3f(xAwal, yAwal - panjangRusuk, zAwal + panjangRusuk);
    glVertex3f(xAwal, yAwal, zAwal + panjangRusuk);
    glEnd();
    //Kanan
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.5, 0);
    glVertex3f(xAwal + panjangRusuk, yAwal, zAwal);
    glVertex3f(xAwal + panjangRusuk, yAwal - panjangRusuk, zAwal);
    glVertex3f(xAwal + panjangRusuk, yAwal - panjangRusuk, zAwal + panjangRusuk);
    glVertex3f(xAwal + panjangRusuk, yAwal, zAwal + panjangRusuk);
    glEnd();
    //Depan
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.5, 0);
    glVertex3f(xAwal, yAwal, zAwal + panjangRusuk);
    glVertex3f(xAwal + panjangRusuk, yAwal, zAwal + panjangRusuk);
    glVertex3f(xAwal + panjangRusuk, yAwal - panjangRusuk, zAwal + panjangRusuk);
    glVertex3f(xAwal, yAwal - panjangRusuk, zAwal + panjangRusuk);
    glEnd();
    //Belakang
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.5, 0);
    glVertex3f(xAwal, yAwal, zAwal);
    glVertex3f(xAwal + panjangRusuk, yAwal, zAwal);
    glVertex3f(xAwal + panjangRusuk, yAwal - panjangRusuk, zAwal);
    glVertex3f(xAwal, yAwal - panjangRusuk, zAwal);
    glEnd();
}


void buatKepala(float xAwal, float yAwal, float zAwal, float panjangRusuk) {
    //Atas
    glBegin(GL_QUADS);
    glColor3f(1, 0.8, 0.8);
    glVertex3f(xAwal - 5, yAwal, zAwal - 5);
    glColor3f(1, 0.5, 0.8);
    glVertex3f(xAwal + panjangRusuk + 5, yAwal, zAwal - 5);
    glColor3f(1, 0.5, 0.8);
    glVertex3f(xAwal + panjangRusuk + 5, yAwal, zAwal + panjangRusuk + 5);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(xAwal - 5, yAwal, zAwal + panjangRusuk + 5);
    glEnd();
    //Bawah
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.5, 0);
    glVertex3f(xAwal - 5, yAwal - panjangRusuk, zAwal - 5);
    glVertex3f(xAwal + panjangRusuk + 5, yAwal - panjangRusuk, zAwal - 5);
    glVertex3f(xAwal + panjangRusuk + 5, yAwal - panjangRusuk, zAwal + panjangRusuk + 5);
    glVertex3f(xAwal - 5, yAwal - panjangRusuk, zAwal + panjangRusuk + 5);
    glEnd();
    //Kiri
    glBegin(GL_QUADS);
    glVertex3f(xAwal - 5, yAwal, zAwal - 5);
    glVertex3f(xAwal - 5, yAwal - panjangRusuk, zAwal - 5);
    glVertex3f(xAwal - 5, yAwal - panjangRusuk, zAwal + panjangRusuk + 5);
    glVertex3f(xAwal - 5, yAwal, zAwal + panjangRusuk + 5);
    glEnd();
    //Kanan
    glBegin(GL_QUADS);
    glVertex3f(xAwal + panjangRusuk + 5, yAwal, zAwal - 5);
    glVertex3f(xAwal + panjangRusuk + 5, yAwal - panjangRusuk, zAwal - 5);
    glVertex3f(xAwal + panjangRusuk + 5, yAwal - panjangRusuk, zAwal + panjangRusuk + 5);
    glVertex3f(xAwal + panjangRusuk + 5, yAwal, zAwal + panjangRusuk + 5);
    glEnd();
    //Depan
    glBegin(GL_QUADS);
    glVertex3f(xAwal - 5, yAwal, zAwal + panjangRusuk + 5);
    glVertex3f(xAwal + panjangRusuk + 5, yAwal, zAwal + panjangRusuk + 5);
    glVertex3f(xAwal + panjangRusuk + 5, yAwal - panjangRusuk, zAwal + panjangRusuk + 5);
    glVertex3f(xAwal - 5, yAwal - panjangRusuk, zAwal + panjangRusuk + 5);
    glEnd();
    //Belakang
    glBegin(GL_QUADS);
    glVertex3f(xAwal - 5, yAwal, zAwal - 5);
    glVertex3f(xAwal + panjangRusuk + 5, yAwal, zAwal - 5);
    glVertex3f(xAwal + panjangRusuk + 5, yAwal - panjangRusuk, zAwal - 5);
    glVertex3f(xAwal - 5, yAwal - panjangRusuk, zAwal - 5);
    glEnd();
}

void zKoordinat() {
    glColor4f(1, 1, 1, 1.0f);
    for (int i = -400; i <= 400; i += 40) {
        glBegin(GL_LINES);
        glVertex3f(i, 0, 400);
        glVertex3f(i, 0, -400);
        glEnd();
        glBegin(GL_LINES);
        glVertex3f(400, 0, i);
        glVertex3f(-400, 0, i);
        glEnd();
    }
}

//Variabel pengaturan
int banyakPoint = 4;
int kordinatX[1000] = { 160,120,80,40 };
int kordinatZ[1000] = { 200,200,200,200 };
int tempX = kordinatX[0];
int tempZ = kordinatZ[0];
int xMakan = -200;
int zMakan = -200;
string arah = "l";
bool makanBadan = false; // Variabel untuk mengecek apakah kordinat kepala = badan?


void cetakBadan() {
    for (int i = 0; i < banyakPoint; i++)
        if (i == 0)
            buatKepala(kordinatX[i], 40, kordinatZ[i], 40);
        else
            buatKubus(kordinatX[i], 40, kordinatZ[i], 40);
}


void cetakMakanan() {
    buatKubus(xMakan, 40, zMakan, 40);
}


void CekDanUpdate() {
    if (kordinatX[0] == xMakan && kordinatZ[0] == zMakan) {
        banyakPoint += 1;
        kordinatX[banyakPoint] = kordinatX[banyakPoint - 1];
        kordinatZ[banyakPoint] = kordinatZ[banyakPoint - 1];
        xMakan = kordinatX[banyakPoint] + 120;
        zMakan = kordinatZ[1] - 240;
        if (xMakan > 360 || xMakan < -400) {
            xMakan = -240;
        }
        if (zMakan < -400 || zMakan > 360) {
            zMakan = 120;
        }
        //score += 1*level;
    }
}


void apakahMakanBadan() {
    if (banyakPoint > 4) {
        for (int i = banyakPoint - 1; i > 3; i--) {
            if (kordinatX[0] == kordinatX[i] && kordinatZ[0] == kordinatZ[i]) {
                makanBadan = true;
                break;
            }
        }
    }
}


void updateKordinat() {
    for (int i = banyakPoint - 1; i > 0; i--) {
        kordinatX[i] = kordinatX[i - 1];
        kordinatZ[i] = kordinatZ[i - 1];
    }
}

void MiniMAP(float xAwal, float yAwal, float zAwal, float panjang, float tinggi, float lebar) {
    //Atas
    glBegin(GL_QUADS);
    glColor3f(0.8, 0.8, 0.8);
    glVertex3f(xAwal, yAwal, zAwal);
    glColor3f(0.7, 0.7, 0.7);
    glVertex3f(xAwal + panjang, yAwal, zAwal);
    glColor3f(0.5, 0.5, 0.5);
    glVertex3f(xAwal + panjang, yAwal, zAwal + lebar);
    glColor3f(0.1, 0.1, 0.1);
    glVertex3f(xAwal, yAwal, zAwal + lebar);
    glEnd();
    //Bawah
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.5, 0);
    glVertex3f(xAwal, yAwal - tinggi, zAwal);
    glColor3f(0.7, 0.6, 0);
    glVertex3f(xAwal + panjang, yAwal - tinggi, zAwal);
    glColor3f(0.8, 0.5, 0);
    glVertex3f(xAwal + panjang, yAwal - tinggi, zAwal + lebar);
    glColor3f(0.7, 0.4, 0);
    glVertex3f(xAwal, yAwal - tinggi, zAwal + lebar);
    glEnd();
    //Kiri
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.5, 0);
    glVertex3f(xAwal, yAwal, zAwal);
    glVertex3f(xAwal, yAwal - tinggi, zAwal);
    glVertex3f(xAwal, yAwal - tinggi, zAwal + lebar);
    glVertex3f(xAwal, yAwal, zAwal + lebar);
    glEnd();
    //Kanan
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.5, 0);
    glVertex3f(xAwal + panjang, yAwal, zAwal);
    glVertex3f(xAwal + panjang, yAwal - tinggi, zAwal);
    glVertex3f(xAwal + panjang, yAwal - tinggi, zAwal + lebar);
    glVertex3f(xAwal + panjang, yAwal, zAwal + lebar);
    glEnd();
    //Depan
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.5, 0);
    glVertex3f(xAwal, yAwal, zAwal + lebar);
    glVertex3f(xAwal + panjang, yAwal, zAwal + lebar);
    glVertex3f(xAwal + panjang, yAwal - tinggi, zAwal + lebar);
    glVertex3f(xAwal, yAwal - tinggi, zAwal + lebar);
    glEnd();
    //Belakang
    glBegin(GL_QUADS);
    glColor3f(0.7, 0.5, 0);
    glVertex3f(xAwal, yAwal, zAwal);
    glVertex3f(xAwal + panjang, yAwal, zAwal);
    glVertex3f(xAwal + panjang, yAwal - tinggi, zAwal);
    glVertex3f(xAwal, yAwal - tinggi, zAwal);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    CameraView();
    cetakBadan();
    cetakMakanan();
    //MiniMAP(-400, 0, -400, 800, 50, 800);
    zKoordinat();
    glPopMatrix();

    CekDanUpdate();

    updateKordinat();

    tempX = kordinatX[0];
    tempZ = kordinatZ[0];
    if (arah == "r")
        kordinatX[0] -= 40;
    if (arah == "l")
        kordinatX[0] += 40;
    if (arah == "t")
        kordinatZ[0] += 40;
    if (arah == "b")
        kordinatZ[0] -= 40;


    if (kordinatX[0] > 360) {
        kordinatX[0] = -400;
    }
    if (kordinatZ[0] > 360) {
        kordinatZ[0] = -400;
    }
    if (kordinatX[0] < -400) {
        kordinatX[0] = 360;
    }
    if (kordinatZ[0] < -400) {
        kordinatZ[0] = 360;
    }

    apakahMakanBadan();

    for (int i = 0; i < 500; i++) {
        cout << "a";
    }


    if (!makanBadan)
        glutPostRedisplay();


    glutSwapBuffers();
}


void keyBoard(unsigned char key, int x, int y) {
    switch (key) {
    case 13:
        exit(0);
        break;
    case 'd':
    case 'D':
        if (arah == "l") {
            break;
        }
        arah = "r"; //right
        break;
    case 'a':
    case 'A':
        if (arah == "r") {
            break;
        }
        arah = "l";
        break;
    case 's':
    case 'S':
        if (arah == "t") {
            break;
        }
        arah = "b";
        break;
    case 'w':
    case 'W':
        if (arah == "b") {
            break;
        }
        arah = "t";
        break;
    }
}


void specialKey(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_DOWN:
        eyeY -= 10;
        break;
    case GLUT_KEY_UP:
        eyeY += 10;
        break;
    case GLUT_KEY_RIGHT:
        phiNow += 10;
        break;
    case GLUT_KEY_LEFT:
        phiNow -= 10;
        break;
    }
}


int main(int iArgc, char** cppArgv) {
    glutInit(&iArgc, cppArgv);
    aturWindows();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyBoard);
    glutSpecialFunc(specialKey);
    //glutIdleFunc(Update);
    glutMainLoop();
    return 0;
}