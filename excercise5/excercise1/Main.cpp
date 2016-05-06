// Michael Kotzjan
// HFU, 25.04.2016

#include <iostream>

using namespace std;

class Rechteck
{
  double laenge;
  double breite;

  public:
  // Getter
  double getBreite()
  {
    return breite;
  }

  double getLaenge()
  {
    return laenge;
  }

  // Setter
  void setBreite(double b)
  {
    breite = b;
  }

  void setLaenge(double l)
  {
    laenge = l;
  }

  // Calculate
  double umfang()
  {
    return 2*(laenge+breite);
  }

  double rFlaeche()
  {
    return laenge*breite;
  }
};

class Quader : public Rechteck
{
  double hoehe;

  public:
  // Getter
  double getHoehe()
  {
    return hoehe;
  }

  // Setter
  void setHoehe(double h)
  {
    hoehe = h;
  }

  // Calculate
  double qFlaeche()
  {
    return (2 * (getBreite() * hoehe)) + (2*(getLaenge() * hoehe)) + (2 * rFlaeche());
  }

  double volumen()
  {
    return hoehe * rFlaeche();
  }
};

int main()
{
  // Test of class Rechteck
  Rechteck r1;

  cout << endl << "Rechteck (1, 5)" << endl;
  r1.setBreite(1);
  r1.setLaenge(5);

  cout << "Breite: " << r1.getBreite() << " cm" << endl;
  cout << "Länge: " << r1.getLaenge() << " cm" << endl;
  cout << "Umfang: " << r1.umfang() << " cm" << endl;
  cout << "Fläche: " << r1.rFlaeche() << " cm²" << endl;

  cout << endl << "Rechteck (2, 4)" << endl;
  r1.setBreite(2);
  r1.setLaenge(4);

  cout << "Breite: " << r1.getBreite() << " cm" << endl;
  cout << "Länge: " << r1.getLaenge() << " cm" << endl;
  cout << "Umfang: " << r1.umfang() << " cm" << endl;
  cout << "Fläche: " << r1.rFlaeche() << " cm²" << endl;

  cout << endl << "Rechteck (2.5, 1.5)" << endl;
  r1.setBreite(2.5);
  r1.setLaenge(1.5);

  cout << "Breite: " << r1.getBreite() << " cm" << endl;
  cout << "Länge: " << r1.getLaenge() << " cm" << endl;
  cout << "Umfang: " << r1.umfang() << " cm" << endl;
  cout << "Fläche: " << r1.rFlaeche() << " cm²" << endl;

  Quader q1;

  cout << endl << "Quader (1, 1, 1)" << endl;
  q1.setBreite(1);
  q1.setLaenge(1);
  q1.setHoehe(1);

  cout << "Breite: " << q1.getBreite() << " cm" << endl;
  cout << "Länge: " << q1.getLaenge() << " cm" << endl;
  cout << "Höhe: " << q1.getHoehe() << " cm" << endl;
  cout << "Fläche: " << q1.qFlaeche() << " cm²" << endl;
  cout << "Volumen: " << q1.volumen() << " cm³" << endl;

  cout << endl << "Quader (2, 2, 2)" << endl;
  q1.setBreite(2);
  q1.setLaenge(2);
  q1.setHoehe(2);

  cout << "Breite: " << q1.getBreite() << " cm" << endl;
  cout << "Länge: " << q1.getLaenge() << " cm" << endl;
  cout << "Höhe: " << q1.getHoehe() << " cm" << endl;
  cout << "Fläche: " << q1.qFlaeche() << " cm²" << endl;
  cout << "Volumen: " << q1.volumen() << " cm³" << endl;

  cout << endl << "Quader (1.5, 2.5, 3.5)" << endl;
  q1.setBreite(1.5);
  q1.setLaenge(2.5);
  q1.setHoehe(3.5);

  cout << "Breite: " << q1.getBreite() << " cm" << endl;
  cout << "Länge: " << q1.getLaenge() << " cm" << endl;
  cout << "Höhe: " << q1.getHoehe() << " cm" << endl;
  cout << "Fläche: " << q1.qFlaeche() << " cm²" << endl;
  cout << "Volumen: " << q1.volumen() << " cm³" << endl;
}
