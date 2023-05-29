#ifndef DOCUMENTMANAGER_H
#define DOCUMENTMANAGER_H

#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

// documents should be unordered_multimap<

struct Document {
  std::string name;
  int license_limit;
  int borrowed;
};

class DocumentManager {
 private:
  std::unordered_map<int, Document> documentsByID;
  std::unordered_map<std::string, int> documentsByName;
  std::unordered_set<int> patrons;
 public:
  DocumentManager();
  void addDocument(std::string name, int id, int license_limit);

  void addPatron(int patronID);

  int search(
      std::string name);  // returns docid if name is in the document collection
                          // or 0 if the name is not in the collection

  bool borrowDocument(
      int docid,
      int patronID);  // returns true if document is borrowed, false if it can
                      // not be borrowed (invalid patronid or the number of
                      // copies current borrowed has reached the license limit)

  void returnDocument(int docid, int patronID);
  ~DocumentManager();
};
#endif
