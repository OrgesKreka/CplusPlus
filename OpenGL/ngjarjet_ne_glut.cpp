///****************************************************************************************
///  Vizatimi i vijave ne ekran dhe ndryshimi i ngjyres sipas tasteve te shtypura.
///
///                         Punoi : Orges Kreka
///****************************************************************************************


#include <GL/glut.h>
#include <vector>
#include <iostream>

using namespace std;


/// Permasat e dritares
const int GJERESIA = 400, GJATESIA = 400;


/// struktura qe ruan pikat e ngjarjes se mausit
struct pika
{
    int x;
    int y;

    float ngjyrat[ 3 ]; /// ruan komponentet e ngjyrave kuqe, gjelber, blu

};


vector< pika > pikat;

float ndryshimiKuqe = 0.0;       ///
float ndryshimiGjelber = 0.0;    ///  variablat qe do ruajne ndryshimet e komponenteve
float ndryshimiBlu = 0.0;         ///



/**
    funksioni Display
*/
void Display ()
{

    glClear( GL_COLOR_BUFFER_BIT );


    glBegin( GL_LINE_STRIP );

        for( int i = 0; i < pikat.size (); i++ )
        {
            int x =  pikat.at( i ).x;
            int y = GJATESIA - pikat.at( i ).y;

            float k, gj, b;

            k = pikat.at( i ).ngjyrat[ 0 ];
            gj = pikat.at( i ).ngjyrat[ 1 ];
            b = pikat.at( i ).ngjyrat[ 2 ];

            glColor3f( k, gj, b );

            glVertex2f( x, y );

        }
    glEnd ();

    glFlush ();

}


/***
    Merr ngjarjet e mausit.
*/
void mouse( int b, int s, int x, int y )
{
    pika p;

    if( b == GLUT_LEFT_BUTTON )
        if( s == GLUT_DOWN )
    {
          p.x = x;
          p.y = y;

     p.ngjyrat[ 0 ] = ndryshimiKuqe;
     p.ngjyrat[ 1 ] = ndryshimiGjelber;
     p.ngjyrat[ 2 ] = ndryshimiBlu;
     pikat.push_back( p );
    }
}


/***
    Merr ngjarjet e tastieres.
*/
void keyboard( unsigned char tasti, int x, int y )
{
    switch( tasti )
    {
        case 'r': ndryshimiKuqe = 0.0; break;
        case 'R': ndryshimiKuqe = 1.0; break;
        case 'g': ndryshimiGjelber = 0.0; break;
        case 'G': ndryshimiGjelber = 1.0; break;
        case 'b': ndryshimiBlu = 0.0; break;
        case 'B': ndryshimiBlu = 1.0; break;

        default:
            cout << "Tast i pavlefshem! \n Provo perseri. . . "; break;
    }


     int n = pikat.size () - 1;

     pikat.at( n ).ngjyrat[ 0 ] = ndryshimiKuqe;
     pikat.at( n ).ngjyrat[ 1 ] = ndryshimiGjelber;
     pikat.at( n ).ngjyrat[ 2 ] = ndryshimiBlu;

}


/**
    Percakton dritaren.
*/
void init ()
{
    glClearColor( 0.5, 0.9, 0.5, 0.0 );
    glLoadIdentity ();
	glOrtho( 0.0, 400.0, 0.0, 400.0,0, 1  );
    glViewport( 0, 0, 400, 400 );
    glMatrixMode( GL_MODELVIEW );
}


/**
    main
*/
int main( int argc, char *argv[] )
{


    glutInit( &argc, argv );
    glutInitDisplayMode ( GLUT_RGB | GLUT_SINGLE );
    glutInitWindowSize( GJERESIA ,GJATESIA );
    glutInitWindowPosition( 200,100 );
    glutCreateWindow( "S e m i n a r" );

    init();
    glutDisplayFunc( Display );
    glutMouseFunc( mouse );
    glutKeyboardFunc( keyboard );
    glutMainLoop ();



    return 0;
}


