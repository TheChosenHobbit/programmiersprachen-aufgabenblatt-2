#ifndef COLOR_HPP
#define COLOR_HPP

struct Color //Ein Strukturtyp ist ein benutzerdefinierter zusammengesetzter Typ.Er setzt sich aus Feldern 
			//oder Membern zusammen, die unterschiedliche Typen aufweisen können.
			//In C++ ist eine Struktur identisch mit einer Klasse, mit der Ausnahme, dass die Member standardmäßig public sind.
{
	float r;
	float g;
	float b;

	Color(float a);
	Color(float a, float b, float c);
};

#endif