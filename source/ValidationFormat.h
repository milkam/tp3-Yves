/**
 * \file ValidationFormat.h
 * \brief Interface du module ValidationFormat.cpp contenant les déclarations des constantes et fonctions.
 * \author Yves Gingras (NI:111102929)
 * \date 2015-11-07
 */

#ifndef VALIDATIONFORMAT_H_
#define VALIDATIONFORMAT_H_
#include <string>

namespace util
{
const std::string PROPRIETES_GEOJSON[] = {"ID", "COTE_RUE", "LECT_MET", "SEGMENT_RU", "DIRECTION", "NOM_TOPOG", "NO_BORNE","NO_CIVIQ ID","VOIE_PUB","GEOM"}; //8  elements
const std::string PROPRIETES_BORNES[] = {"ID", "COTE_RUE", "LECT_MET", "SEGMENT_RU", "DIRECTION", "NOM_TOPOG", "NO_BORNE", "LONGITUDE", "LATITUDE"}; //9 elements
const std::string POINTS_CARDINAUX [] = {"Nord","Sud","Est","Ouest","null",""};
const int NB_PROP_GEOJSON = 10;
const int NB_PROP_BORNES = 9;
const int NB_POINTS_CARDINAUX = 6;


bool valideLigneGEOJSON (std::string& p_ligne, std::ostringstream& p_parametres);
bool valideLigneCVS (std::string& p_ligne, std::ostringstream& p_parametres);
bool validerGeom(const std::string& p_geom);
bool validerPointCardinal(const std::string& p_cardinalite);


}
#endif /* VALIDATIONFORMAT_H_ */

