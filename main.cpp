#include <windows.h>
#include <C:\GLUT\include\GL\glut.h>
#include <stdlib.h>
#include <stdio.h>

GLfloat escala = 1;
GLfloat movex, movey;
void Desenha (void){
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-82,82,-82,82);

    glScalef(escala,escala,0);
    glTranslatef(movex,movey,0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glBegin(GL_QUADS);
        glColor3f(0,0,1);
        glVertex2f(2,-2);
        glVertex2f(2,2);
        glColor3f(1,1,1);
        glVertex2d(-2,2);
        glVertex2d(-2,-2);
        glColor3f(1,0,0);
    glEnd();
    glFlush();
}

void Teclas(unsigned char teclas, GLint x, GLint y){
    switch(teclas){
    case 27 :
    case 'q':
        exit(0);
        break;
    }
    Desenha();
}

void TeclasEspeciais(GLint teclas, GLint x, GLint y){
    int aux;

    switch(teclas){
    case GLUT_KEY_UP:
        movey++;
        break;
    case GLUT_KEY_DOWN:
        movey--;
        break;
    case GLUT_KEY_LEFT:
        movex--;
        break;
    case GLUT_KEY_RIGHT:
        movex++;
        break;
    case GLUT_KEY_HOME:
        escala = (escala - escala) + 1 ;
        movex = movex - movex;
        movey = movey - movey;
        break;
    case GLUT_KEY_PAGE_UP:
        aux = escala /2;
        escala = escala + aux;
        break;
    case GLUT_KEY_PAGE_DOWN:
        aux = escala /2;
        escala = escala - aux;
        break;
    }
    Desenha();

}

void mouse(int button, int state, int x, int y) {
      switch(button){
        case GLUT_LEFT_BUTTON:
            escala = escala + 0.25;
            break;
        case GLUT_RIGHT_BUTTON:
            if(escala > 0.25){
            escala = escala -0.25;
            break;
            }
        }
        Desenha();
}

int main(void){
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(260,40);
    glutCreateWindow("Programa");
    glutKeyboardFunc(Teclas);
    glutDisplayFunc(Desenha);
    glutMouseFunc(mouse);
    glutSpecialFunc(TeclasEspeciais);
    glClearColor(0,0,0,0);
    glutMainLoop();

    return 0;
}
