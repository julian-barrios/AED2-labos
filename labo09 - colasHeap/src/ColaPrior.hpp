template<class T>
ColaPrior<T>::ColaPrior() {
	v_ = {};
}

template<class T>
int ColaPrior<T>::tam() const {
	v_.size();
}

template<class T>
void ColaPrior<T>::encolar(const T& elem) {
    v_.push_back(elem);
    siftUp(v_.size() - 1);
}


template<class T>
const T& ColaPrior<T>::proximo() const {
	return v_[0];
}

template<class T>
void ColaPrior<T>::desencolar() {
    swap(v_.back(), v_[0]);
    v_.pop_back();
    siftDown(0);
}

template<class T>
ColaPrior<T>::ColaPrior(const vector<T>& elems) {
    for(int i = 0; i < elems.size(); i++){
        v_.push_back(elems[i]) ;
        siftUp(v_.size() - 1);
    }
}

// -----------------------------------------------------


template<class T>
void ColaPrior<T>::siftUp(int i) {
    if (v_.size() > 1) {
        if (v_[i] > v_[PADRE(i)]) {
            swap(v_[i], v_[PADRE(i)]);
            siftUp( PADRE(i));
        }
    }
}

template<class T>
void ColaPrior<T>::siftDown(int i){
    if(!esHoja(i)){
        T m;
        if(HIJO_DER(i) > v_.size() - 1){
            m = v_[HIJO_IZQ(i)];
        } else {
            m = max(v_[HIJO_IZQ(i)], v_[HIJO_DER(i)]);
        }
        int ind = indice(m);
        if(m > v_[i]){
            swap(v_[i], v_[ind]);
            siftDown(ind);
        }
    }
}

template<class T>
bool ColaPrior<T>::esHoja(int i) {
    return (HIJO_IZQ(i) <= 0 || HIJO_IZQ(i) >= v_.size()) && (HIJO_DER(i) <= 0 || HIJO_DER(i) >= v_.size());
}

template<class T>
T ColaPrior<T>::HIJO_IZQ(int i) {
    return 2*i+1;
}

template<class T>
T ColaPrior<T>::HIJO_DER(int i) {
    return 2*i+2;
}
template<class T>
T ColaPrior<T>::PADRE(int i) {
    return (i-1)/2;
}

template<class T>
void ColaPrior<T>::swap(T &elem1, T &elem2){
    T aux = elem1;
    elem1 = elem2;
    elem2 = aux;
}

template<class T>
int ColaPrior<T>::indice(T elem) {
    int i = 0;
    while(i < v_.size() && v_[i] != elem){
        i++;
    }
    return i;
}
