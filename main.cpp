#include<GL/glut.h>
#include<iostream>
#include<math.h>
void init2D(float r, float g, float b) {
glClearColor(1.0, 1.0, 1.0, 1.0); // Arka plan rengi -- beyaz RGBA formatýnda
gluOrtho2D(0.0, 220.0, 0.0, 220.0); //GLUT pencere çizim alaný büyüklüðü
}
void display(void) {
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(0.0, 0.0, 0.0); //ekrandaki noktalarýn rengini belirler - RGB formatýnda
glPointSize(5.0f); //ekrandaki noktalarýn büyüklüðünü belirler
glBegin(GL_POINTS); // Draw a square using individual points
   for (int i = 10; i <= 210; i++) { 
      for (int j = 10; j <= 210; j++) {
         if (i == 10 || i == 210 || j == 10 || j == 210) {
            glVertex2i(i, j);
         }
      }
   }
   for (int i = 10; i <= 210; i++) { 
      for (int j = 10; j <= 210; j++) {
         if (j <= 110 && j >= -(i - 110) && j >= i - 110) {
            glVertex2i(i, j);
         }
      }
   }
   	int centerX = 110;
    int centerY = 110;
    int radius = 50;
    for (int i = 10; i <= 210; i++) { 
        for (int j = 10; j <= 210; j++) {
            int distX = i - centerX;
            int distY = j - centerY;
            int distance = sqrt(distX * distX + distY * distY);
            if (distance >= radius - 1 && distance <= radius + 1) {
                glVertex2i(i, j);
            }
        }
    }
glEnd();
glFlush();	

}
int main(int argc, char *argv[]) {
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
glutInitWindowPosition(500, 200); //glut penceresinin ekran konumu
glutInitWindowSize(500, 600); //glut penceresinin boyutlarý
glutCreateWindow("OpenGL Merhaba Dünya");
init2D(0.0, 0.0, 0.0);
glutDisplayFunc(display);
glutMainLoop();
return 0;
}
