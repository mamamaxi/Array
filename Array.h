namespace array {
template <typename T, size_t size> class Array {
    private:
        T Arr[]; 
    public:
        Array::Array(){ // non initialisé
            Arr = nullptr;
            size = 0
        };
        Array::Array(typename Type, int howBigIsThisArray){ // avec initialisation
            Arr = Type[size]
        }

        int size(Array tab){
            return size;
        };  //renvoie le size du tableau envoyé

        bool empty(Array tab){
            if (size == 0)
            {
                return true;
            }
            return false;
        }; //vérifie si le tableau est vide

        //operator[], prend la valeur à [x]
        template <typename T>
        T* Array<T>::operator[](int x){
            return Arr[x];
        }

        //prend la valeur à (x) avec verification
        T* Array::at(int x){
            return Arr[x]
        }

        T* Array::front(Array tab){
            return tab[0];
        }      //valeur du premier element
        T* Array::back(Array tab){
            return tab[size - 1];
        }       //valeur du dernier element 
        void fill(volatile value, Array tab){
            for (size_t i = 0; i < size; i++)
            {
                tab[i] = value
            }
            
        }   //met la valeur choisi dans chaque cellules du tableau
        void swap(Array tab1, Array tab2){
            if (tab1.size == tab2.size)
            {
                T tab3[size] = tab1;
                tab1 = tab2;
                tab2 = tab3;
                
            }
        }     //échange les valeurs des deux tableaux

        Array fusion(Array tab1, Array tab2){

        }  //fusionne 2 tableaux
        Array subset(Array entry, Array retour,int start, int length){

        }   //crée un nouveau tableau avec les valeurs entre start et start + length et le met dans le tableau retour
        T* begin(){

        }                   //retourne un iterateur au début du tableau
        const T* cbegin(){

        }                  //retourne un iterateur constant au début du tableau
        T* end(Array tab){

        }           //retourne un iterateur a la fin du tableau
        const T* cend(Array tab){
            
        }           //retourne un iterateur constant a la fin du tableau
    };
}