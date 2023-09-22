#include <stdexcept>
#include <iostream>

template <typename T, size_t dim> 
class Array {
    private:
        T* Arr;
        size_t grandeur;

    public:
        Array(){ // non initialisé
            Arr = new T[dim];
            grandeur = dim;
        };

        ~Array(){
            delete[] Arr;
        }

        Array(T tab[]){ // avec initialisation
            Arr = new T[dim];
            grandeur = dim;
            for (size_t i = 0; i < grandeur; i++)
                Arr[i] = tab[i];
        };

        Array(T* tab[]){ // avec initialisation
            Arr = tab;
        };

        Array(const Array& a){
            Arr = new T[a.grandeur];
            grandeur = a.grandeur;
            for (size_t i = 0; i < grandeur; i++)
                Arr[i] = a[i];
        };

        Array(Array&& a){
            Arr = a.Arr;
            a.Arr = nullptr;
            grandeur = a.grandeur;
        };

        size_t size() const {
            return grandeur;
        };  //renvoie le size du tableau envoyé

        bool empty() const {
            return grandeur == 0;
        }; //vérifie si le tableau est vide

        //operator[], prend la valeur à [x]
        T& operator[](size_t x){
            return Arr[x];
        };

        //prend la valeur à (x) avec verification
        T& at(int x){
            if (x >= grandeur)
                throw std::out_of_range("Index out of range");
            return Arr[x];
        };

        T& front(){
            return Arr[0];
        }; //valeur du premier element

        T& back(){
            return Arr[grandeur - 1];
        }; //valeur du dernier element 

        void fill(T value){
            for (int i = 0; i < grandeur; i++)
                Arr[i] = value;
        };//met la valeur choisi dans chaque cellules du tableau

        void swap(Array tab1, Array tab2){
            if (tab1.grandeur == tab2.grandeur)
            {
                T *tmp[grandeur] = tab1;
                tab1 = tab2;
                tab2 = tmp;
            }
        };//échange les valeurs des deux tableaux

        Array fusion(const Array tab1,const Array tab2){
            if (tab1.size() != tab2.size())
                throw std::runtime_error("Arrays have different sizes");
            
            Array<T, dim> tab;

            for (int i = 0; i < tab1.size(); ++i) {
                tab[i] = tab1[i] + tab2[i]; 
            }
            return tab;

        };//fusionne 2 tableaux

        Array subset(int depart, int duree) {
            // Vérifier que l'indice de départ est valide
            if (depart < 0 || depart >= static_cast<int>(grandeur)) {
                 throw std::runtime_error("start value isnt valid");
            }

            Array<T, dim> tab;
            int counter = 0;

            // Copier les éléments du tableau d'origine dans le nouveau tableau
            for (int i = depart; i < depart + duree && i < tab.size(); i++) {
                tab[counter] = Arr[i];
                counter++;
            }
            return tab;
        }

        class Iterator{
            private:
            T* ptr;
            public:
                Iterator() : ptr(nullptr){}
                Iterator(T* p) : ptr(p){}
                //~Iterator(){};

                T& operator*(){
                    return *ptr;
                }

                Iterator& operator++() {
                    ++ptr;
                    return *this;
                }

                Iterator& operator--(){
                    --ptr;
                    return *this;
                }

                bool operator==(const Iterator& iterator2) const {
                    return ptr == iterator2.ptr;
                }
                bool operator!=(const Iterator& iterator2) const {
                    return ptr != iterator2.ptr;
                }
        };  
        
        Iterator begin(){
            return Iterator(Arr);
        };//retourne un iterateur au début du tableau

        const Iterator cbegin() const {
            return Iterator(Arr);
        };//retourne un iterateur constant au début du tableau

        Iterator end(Array tab){
            return Iterator(Arr + grandeur);
        };//retourne un iterateur a la fin du tableau

        const Iterator cend(Array tab) const {
            return Iterator(Arr + grandeur);
        };//retourne un iterateur constant a la fin du tableau 
};