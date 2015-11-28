/**
 * \file ValidationFormat.cpp
 * \brief Fichier contenant des fonctions de valisation associe à l'utilisation de la classe Borne.
 * \author Yves Gingras (NI:111102929)
 * \date 2015-11-07
 */


#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

#include "ValidationFormat.h"

using namespace std;
namespace util
{
/**
 * \brief Valide si la quantité de champs reçu correspond au nombre de
 * 	 	  paramètres requis pour la norme GEOJSON.
 * \param[in] p_ligne: 		string passé en référence, contenant la chaine à valider
 * \param[in] p_parametres: ostringstream passé en référence dans lequel la fonction placera
 * 			 				la valeur des champs contenu dans "p_lighe", formatés dans l'ordre des propriétés
 *
 * \return Un booléen qui indique si le nombre de champs correspond au nombre de propriétés.
 */
bool valideLigneGEOJSON (std::string& p_ligne, std::ostringstream& p_parametres)
{

	string tempString;
	char buffer[256];
	int compteurTemp = 0;


	istringstream monIStrStream(p_ligne);
	while (monIStrStream.getline(buffer, 255, ','))
	{
		compteurTemp++;
		p_parametres << (string) buffer << '\n';
	}

	//valider qu'il y autant de champs que de propriétés. Terminer et retourner "false" sinon.
		if (compteurTemp != NB_PROP_GEOJSON)
		{
			return false;
		}

	return true;
}

/**
 * \brief Valide si la quantité de champs reçu correspond au nombre de paramètres <br>
 * 		  requis pour le type de données associées aux bormes de stationnement.
 * \param[in] p_ligne: 		string passé en référence, contenant la chaine à valider
 * \param[in] p_parametres: ostringstream passé en référence dans lequel la fonction placera
 * 			 				la valeur des champs contenu dans "p_lighe", formatés dans l'ordre des propriétés
 *
 * \return Un booléen qui indique si le nombre de champs correspond au nombre de propriétés.
 */
bool valideLigneCVS (std::string& p_ligne, std::ostringstream& p_parametres)
{
	int compteurTemp = 0;
	string stringTemp;
	char buffer[256];

	// initialise l'addresse mmémoire de "p_parametres" puisque la même variable est utilisée pour tous les appels de fonctions du programme.
	p_parametres.str("");

	// instancer un objet "istringsream" avec la chaine reçu en paramètre.
	istringstream monIStrStream(p_ligne);

	// boucler pour stocker dans "p_parametres" chaque section de caractères délimité par '|', ajouter un espace et compter le nombre de boucles.
	while (monIStrStream.getline(buffer, 255, '|'))
	{
		compteurTemp++;
		p_parametres << (string) buffer + ' ';
	}

	//retirer le dernier espace en utilisant une variable temporaire.
	for (unsigned int i = 0; i < p_parametres.str().length() - 1; i++)
	{
		stringTemp += p_parametres.str()[i];
	}

	//réassigner la chaîne tronquée à "p_parametres".
	p_parametres.str(stringTemp);

	//valider qu'il y autant de champs que de propriétés. Terminer et retourner "false" sinon.
	if (compteurTemp != NB_PROP_BORNES)
	{
		return false;
	}

	return true;
}

/**
 * \brief Fonction validant si le format de donnée entrée correspond au format requis
 * \param[in] p_geom: La coordonnée géodésique à valider.
 * \return Un booléen indiquant si la format de donnée est conforme ou non.
 */
bool validerGeom(const std::string& p_geom)
{
	int compteurTemp = 0;
	char buffer[256];

	istringstream monIStrStream(p_geom);

	while (monIStrStream.getline(buffer, 255, ' ' ))
	{
		for (int i = 0; buffer[i] != '\0'; ++i)
		{
			if (buffer[i] == '.')
			{
				compteurTemp++;
			}
		}

		if (compteurTemp != 1 )
		{
			return false;
		}
		else
		{
			compteurTemp = 0;
		}
	}

	return true;
}

/**
 * \brief Fonction permettant de valider la "légalité" du point cardinal passé en argument.
 * \param[in] p_cardinalite: string contenant un point cardinal
 * \return Un booléen indiquant si le point cardinal et "légal" ou non.
 */
//bool validerPointCardinal(const std::string& p_cardinalite)
//bool validerPointCardinal(const std::string& p_cardinalite)
bool validerPointCardinal(const std::string& p_cardinalite)
{
	//boucle dans le tableau contenant la définition des points cardinaux "légaux", Retourne "true" si "p_cardinalite" en est un.
	for (int i = 0; i < NB_POINTS_CARDINAUX - 1; ++i)
	{
		if (p_cardinalite.compare(POINTS_CARDINAUX[i]) == 0 || p_cardinalite == "" )
		{
			return true;
		}
	}

	return false; // pas trouver de point cardinal légal.
}
} //namespace util

//int main ()
//{
//ostringstream p_parametres;
//	string p_ligne = "";
//	string p_geom = "";
//
//	p_ligne = "\"ID\":\"300070\",\"COTE_RUE\":\"Ouest\",\"LECT_MET\":\"208\",\"SEGMENT_RU\":\"105\",\"DIRECTION\":null,\"NOM_TOPOG\":\"Avenue Louis-St-Laurent\",\"NO_BORNE\":\"2371\",\"NO_CIVIQ\":null,\"ID_VOIE_PUB\":105663,\"GEOM\":\"POINT (249714.049 5185174.046)\"";
//	cout << valideLigneGEOJSON(p_ligne, p_parametres) << endl;
//	cout << "Voice le contenu de p_parametres:\n"<< p_parametres.str() << endl;
//
//	p_ligne = "300685|Sud|53,58|2,0||Boulevard René-Lévesque Ouest|B19|-71,225995|46,804545";
//	cout << "\n" << valideLigneCVS(p_ligne, p_parametres) << endl;
//	cout << "Voice le contenu de p_parametres:\n"<< p_parametres.str() << "." << endl;
//
//	p_geom = "249714.049 5185174.046";
//	cout << "\n"  << validerGeom(p_geom) << endl;
//	cout << "Voice le contenu de p_geom:\n"<< p_geom << "." << endl;
//
//	string p_direction = "";
//	cout << "\n"  << validerPointCardinal(p_direction) << endl;
//	cout << "Voice le contenu de p_direction:\n"<< p_direction << "." << endl;
//
//	return 0;
//}
