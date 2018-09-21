#include <iostream>
#include <cmath>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
#define longitud 11

class Regresion {
	private:
		double* x;
		double* y;
		double* xy;
		double* x2;
		double* y2;
		double covXY;
		double desvx;
		double desvy;
		double promx;
		double promy;
		double sx;
		double sy;
		double sxy;
		double sx2;
		double sy2;
		double r;
		double nY;
		double nX;
		double num;
	public:
		Regresion() {
			/*double tx[] = { 14,7,13,12,16,14,18,13,12,16,13 };
			double ty[] = { 16,12,13,14,15,12,16,11,13,18,17 };
			x = tx;
			y = ty;*/
			xy = new double[longitud];
			x2 = new double [longitud];
			y2 = new double [longitud];		
			sx = 0, sy = 0, sxy = 0, sx2 = 0, sy2 = 0;
			leerArchivo();
			calcularMatriz();
			calcularPromedio();
			calcularCovarianza();
			calcularDesviaciones();
			calcularR();
			calcularNewY();
			calcularNewX();
		}
		void leerArchivo() {
			ifstream arch("datos.csv");
			string registro, cadena;
			short c = 0;
			x = new double[longitud];
			y = new double[longitud];
			while (getline(arch, registro)){
				stringstream ss(registro);
				getline(ss, cadena, ',');
				x[c] = atof(cadena.c_str());
				//cout << cadena << endl;
				getline(ss, cadena);
				y[c] = atof(cadena.c_str());
				c++;
				//cout << cadena << endl;
			}
		}
		void calcularMatriz() {
		
			for (int i = 0; i < longitud; ++i) {
				xy[i] = x[i] * y[i];
				x2[i] = pow(x[i], 2);
				y2[i] = pow(y[i], 2);
			}
			for (int i = 0; i < longitud; ++i) {
				sx = sx + x[i];
				sy = sy + y[i];
				sxy = sxy + xy[i];
				sx2 = sx2 + x2[i];
				sy2 = sy2 + y2[i];
			}
		}
		void calcularPromedio() {
			promx = sx / longitud;
			promy = sy / longitud;
		}
		void calcularCovarianza() {
			covXY = (sxy / longitud) - (promx*promy);
		}
		void calcularDesviaciones(){
			desvx = sqrt((sx2 / longitud) - pow(promx, 2));
			desvy = sqrt((sy2 / longitud) - pow(promy, 2));	
		}
		void calcularR() {
			r = (covXY) / (desvx*desvy);
		}
		void calcularNewY(){
		    cout <<  "Introduce el valor de X: ";
		    cin >> num;
		    nY = ((covXY/(pow(desvx,2)))*(num-promx))+promy;
		}
		void calcularNewX(){
		    cout <<  "Introduce el valor de Y: ";
		    cin >> num;
		    nX = ((covXY/(pow(desvy,2)))*(num-promy))+promx;
		}
		void visualizar() {
			cout << "El promedio de X es: " << promx << endl;
			cout << "El promedio de Y es: " << promy << endl;
			cout << "La covarianza es: " << covXY << endl;
			cout << "La desviación de X es: " << desvx << endl;
			cout << "La desviación de Y es: " << desvy << endl;
			cout << "El coeficiente de correlación: " << r << endl;
			cout << "El Nuevo Valor de Y es: " << nY << endl;
			cout << "El Nuevo Valor de X es: " << nX << endl;
		}
};

int main() {
	Regresion r;
	r.visualizar();
	cin.get();
}
