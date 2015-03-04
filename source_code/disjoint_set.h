

struct disjoint_set{
  disjoint_set* parent;
  int rank;
  disjoint_set() { parent = this; rank = 0;}

  disjoint_set* find_root(){
    if(parent == this) //this is root
      return this;
    else
      return parent->find_root(); //delegate to the parent set
  }

  void union_set(disjoint_set* other){
    auto thisRoot = find_root();
    auto thatRoot = other->find_root();
    if(thisRoot == thatRoot)
      return; //we are already in the same set
    //merge
    if(thisRoot->rank < thatRoot->rank)
      thisRoot->parent = thatRoot;
    else if(thisRoot->rank > thatRoot->rank)
      thatRoot->parent = thisRoot;
    else{
      thatRoot->parent = thisRoot;
      thisRoot->rank = thatRoot->rank + 1;
    }
  }
};