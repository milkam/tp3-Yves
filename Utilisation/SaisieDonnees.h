/**
 * \file SaisieDonnees.h
 * \brief Fichier contenan l'interface du module "SaisiesDonnees".
 * \author Yves Gingras (NI:111102929)
 * \date 2015-11-24
 */

#ifndef SAISIEDONNEES_H_
#define SAISIEDONNEES_H_

const int NB_PARAMETRES_BORNE = 5; ///< Utilisé pour controler les boucles d'un while.
const int NB_PARAMETRES_BORNE_STATIONNEMENT = 5; ///< Utilisé pour controler les boucles d'un while.
const int NB_PARAMETRES_BORNE_FONTAINE = 2; ///< Utilisé pour controler les boucles d'un while.

std::string saisirDonneesBorne();
std::string saisirDonneesBorneStationnement();
std::string saisirDonneesBorneFontaine();


#endif /* SAISIEDONNEES_H_ */
