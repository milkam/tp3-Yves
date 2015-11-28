/**
 * \file SaisieDonnees.cpp
 * \brief Fichier contenant des fonctions associées aux saisies de données des bornes.
 * \author Yves Gingras (NI:111102929)
 * \date 2015-11-24
 */

#include <string>
#include <iostream>
#include <sstream>
#include "SaisieDonnees.h"
#include "ValidationFormat.h"
#include <stdlib.h>

using namespace std;
using namespace util;

//using namespace tp;

/**
 * \fn string saisirDonneesBorne()
 * \brief Cette fonction permet de valider et saisir les données génériques de bornes.
 *
 * \return ostringstream contenant les valeurs associés à chacun des paramètres\n
 * 						 requis pour construire un objet de type Borne.
 */
string saisirDonneesBorne()
{
	ostringstream osValeursBorne;
	char buffer[256];
	string entreeCourante;


	int unsigned compteurParametres = 0;
//	cin.ignore();

	while (compteurParametres < NB_PARAMETRES_BORNE_STATIONNEMENT)
	{
		switch (compteurParametres)
		{
			case 0: //idBorne
				cout << "\nEntrez \"idBorne\": " << endl;
				cin.getline(buffer,255);
				entreeCourante = buffer;
				entreeCourante += " ";
				osValeursBorne << entreeCourante;
				break;

			case 1: //direction
				cout << "\nEntrez \"direction\": " << endl;
//				if (cin.get() == '\n') // si "Enter" vide
//				{
//					entreeCourante = "";
//				}
//				else
//				{
//					cin.getline(buffer,255);
//					entreeCourante = buffer;
//				}
				cin.getline(buffer,255);
				entreeCourante = buffer;

				if (validerPointCardinal(entreeCourante))
				{
					entreeCourante += " ";
					osValeursBorne << entreeCourante;
				}
				else
				{
					cout << "\"direction\" doit contenir une des valeurs suivantes:" <<
							"\nNord, Sud, Est, Ouest, null, « chaine vide »." << endl;
					compteurParametres--; //prochaine boucle dans le même "case".
				}
				break;

			case 2: //longitude
				cout << "\nEntrez \"longitude\": " << endl;
				cin.getline(buffer,255);
				entreeCourante = buffer;
				entreeCourante += " ";
				osValeursBorne << entreeCourante;
				break;

			case 3: //latitude
				cout << "\nEntrez \"latitude\": " << endl;
				cin.getline(buffer,255);
				entreeCourante = buffer;
				entreeCourante += " ";
				osValeursBorne << entreeCourante;
				break;

			case 4: //nomTopographique
//				cin.ignore();
				cout << "\nEntrez \"nomTopographique\": " << endl;
				cin.getline(buffer,255);
				entreeCourante = buffer;
				if (entreeCourante != "")
				{
					entreeCourante += " ";
					osValeursBorne << entreeCourante;
				}
				else
				{
					cout << "\"nomTopographique\" ne peut être vide!" << endl;
					compteurParametres--; //prochaine boucle dans le même "case".
				}
				break;
		}

		compteurParametres++;
	}
	return osValeursBorne.str();
}

/**
 * \fn string saisirDonneesBorneStationnement()
 * \brief Cette fonction permet de valider et saisir les données spécifiques aux de bonrnes de stationnnement.
 *
 * \return ostringstream contenant les valeurs associés à chacun des paramètres\n
 * 						 requis pour construire un objet de type BorneStationnement.
 */
string saisirDonneesBorneStationnement()
{
	ostringstream osValeursBorneStationnement;
	char buffer[256];
	string entreeCourante;
	double tempDouble; // utililser pour passer le double convertit de  "cin", et faire une comparaison numérique.
	int tempInteger; // utililser pour passer le int convertit de  "cin", et faire une évaluation comparaison numérique.
	int unsigned compteurParametres = 0;


		while (compteurParametres < NB_PARAMETRES_BORNE)
		{
			switch (compteurParametres)
			{
				case 0: //type
					cout << "\nEntrez \"type\": " << endl;
					cin.getline(buffer,255);
					entreeCourante = buffer;

					if (entreeCourante == "stationnement" || entreeCourante == "paiement")
					{
						entreeCourante += " ";
						osValeursBorneStationnement << entreeCourante;
					}
					else
					{
						cout << "La valeur de \"type\" doit être \"stationnement\" ou \"paiement\"!" << endl;
						compteurParametres--; //prochaine boucle dans le même "case".
					}

				break;

				case 1: //lectureMetrique
					cout << "\nEntrez \"lectureMetrique\": " << endl;
					cin.getline(buffer,255);
					entreeCourante = buffer;
					tempDouble = atof(buffer); //Utiliser pour l'évaluation comparative

					if (tempDouble > 0)
					{
						entreeCourante += " ";
						osValeursBorneStationnement << entreeCourante;
					}
					else
					{
						cout << "La valeur de \"lectureMetrique\" doit être plus grand que 0!" << endl;
						compteurParametres--; //prochaine boucle dans le même "case".
					}
					break;

				case 2: //segmentRue
					cout << "\nEntrez \"segmentRue\": " << endl;
					cin.getline(buffer,255);
					entreeCourante = buffer;
					tempInteger = atoi(buffer);

					if (tempInteger > 0)
					{
						entreeCourante += " ";
						osValeursBorneStationnement << entreeCourante;
					}
					else
					{
						cout << "La valeur de \"segmentRue\" doit être plus grand que 0!" << endl;
						compteurParametres--; //prochaine boucle dans le même "case".
					}
					break;

				case 3: //numBorne
					cout << "\nEntrez \"numBorne\": " << endl;
					cin.getline(buffer,255);
					entreeCourante = buffer;

					if (entreeCourante != "")
					{
						entreeCourante += " ";
						osValeursBorneStationnement << entreeCourante;
					}
					else
					{
						cout << "\"numBorne\" ne doit pas être vide!" << endl;
						compteurParametres--; //prochaine boucle dans le même "case".
					}
					break;

				case 4: //p_coteRue
					cout << "\nEntrez \"coteRue\": " << endl;
					cin.getline(buffer,255);
					entreeCourante = buffer;
					if (validerPointCardinal(entreeCourante))
					{
						entreeCourante += " ";
						osValeursBorneStationnement << entreeCourante;
					}
					else
					{
						cout << "\"coteRue\" doit contenir une des valeurs suivantes:" <<
								"\nNord, Sud, Est, Ouest, null, « chaine vide »." << endl;
						compteurParametres--; //prochaine boucle dans le même "case".
					}
					break;

				}
			compteurParametres++; //prochaine entrée
		}
			return osValeursBorneStationnement.str();
}

/**
 * \fn string saisirDonneesBorneFontaine()
 * \brief Cette fonction permet de valider et saisir les données spécifiques aux bornes fontaine.
 *
 * \return ostringstream contenant les valeurs associés à chacun des paramètres\n
 * 						 requis pour construire un objet de type Borne.
 */
string saisirDonneesBorneFontaine()
{
	ostringstream osValeursBorneFontaine;
	char buffer[256];
	string entreeCourante;
	string tempVille = "";
	int unsigned compteurParametres = 0;

	while (compteurParametres < NB_PARAMETRES_BORNE_FONTAINE)
	{
		switch (compteurParametres)
		{
			case 0: //idBorne
				cout << "\nEntrez \"ville\": " << endl;
				cin.getline(buffer,255);
				entreeCourante = buffer;
				tempVille = buffer; // pour évaluation de la condition arrondissement/ville
				entreeCourante += " ";
				osValeursBorneFontaine << entreeCourante;
				break;

			case 1: //numBorne
				cout << "\nEntrez \"arrondissement\": " << endl;
				cin.getline(buffer,255);
				entreeCourante = buffer;

				if (!(tempVille.compare("Québec") == 0 && entreeCourante.empty()))
				{
					entreeCourante += " ";
					osValeursBorneFontaine << entreeCourante;
				}
				else
				{
					cout << "\"arrondissememt ne peut être vide lorsque la ville est \"Québec\"!" << endl;
					compteurParametres--; //prochaine boucle dans le même "case".
				}
				break;
		}
		compteurParametres++; //prochaine entrée
	}


	return osValeursBorneFontaine.str();
}

