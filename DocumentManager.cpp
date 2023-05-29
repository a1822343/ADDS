#include "DocumentManager.h"

DocumentManager::DocumentManager() {}

void DocumentManager::addDocument(std::string name, int id, int license_limit) {
  documentsByID.insert({id, {name, license_limit, 0}});
  documentsByName.insert({name, id});
  return;
}

void DocumentManager::addPatron(int patronID) {
  patrons.insert(patronID);
  return;
}

int DocumentManager::search(std::string name) {
  if (documentsByName.find(name) != documentsByName.end()) {
    return documentsByName.at(name);
  }
  return 0;
}

bool DocumentManager::borrowDocument(int docid, int patronID) {
  if (patrons.find(patronID) != patrons.end() && documentsByID.find(docid) != documentsByID.end() && documentsByID.at(docid).borrowed < documentsByID.at(docid).license_limit) {
    documentsByID.at(docid).borrowed++;
    return true;
  } 
  return false;
}

void DocumentManager::returnDocument(int docid, int patronID) {
  if (patrons.find(patronID) != patrons.end() && documentsByID.find(docid) != documentsByID.end() && documentsByID.at(docid).borrowed > 0) {
    documentsByID.at(docid).borrowed--;
  }
  return;
}

DocumentManager::~DocumentManager() {}