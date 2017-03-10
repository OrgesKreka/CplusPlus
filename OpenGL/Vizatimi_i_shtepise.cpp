#include<windows.h>
#include<GL/glut.h>

void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h);
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
   gluOrtho2D (0.0, (GLdouble) w, 0.0, (GLdouble) h);
}

void vizatoShtepine ()
{
    glClearColor( 1.0, 0.0, 0.0, 1.0 );

    glClear( GL_COLOR_BUFFER_BIT );

    /// Vizaton trupin e shtepise
    glBegin( GL_QUADS );

        glColor3f( 0.0, 1.0, 1.0 );

        glVertex2i( 100, 100 );
        glVertex2i( 400, 100 );
        glVertex2i( 400, 300 );
        glVertex2i( 100, 300 );

    glEnd();


    /// vizaton catine
    glBegin( GL_TRIANGLES );
        glColor3f( 0.0, 1.0, 0.0 );

        glVertex2i( 250, 450 );
        glVertex2i( 100, 300 );
        glVertex2i( 400, 300 );

    glEnd();


    ///Vizaton deren
    glBegin( GL_QUADS );
        glColor3i( 0, 0, 0 );

        glVertex2i( 195, 100 );
        glVertex2i( 250, 100 );
        glVertex2i( 250, 175 );
        glVertex2i( 195, 175 );
    glEnd();


    glFlush ();
} ///FUND trekendesh

int main( int argc, char** argv )
{
    glutInit( &argc, argv );

    glutCreateWindow( "Trekendesh ne OpenGL" );

    glutInitWindowSize( 800, 500 );

    glutInitWindowPosition( 800, 800 );

    reshape( 500, 500 );

    glutDisplayFunc( vizatoShtepine );

    glutMainLoop();
}


