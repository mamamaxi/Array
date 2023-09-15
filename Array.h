namespace array {
    class Array
    {
    public:
    //changer les array pour le taleau, ils utilise ce namespace en ce moment
        Array();
        int size(array tab);            //renvoie le size du tableau envoyé
        bool empty(array tab);          //vérifie si le tableau est vide
        //operator[]                    //prend la valeur à [x]
        //.at()                         //prend la valeur à (x) avec verification
        volatile front(array tab);      //valeur du premier element
        volatile back(array tab);       //valeur du dernier element 
        void fill(volatile value, array tab);   //met la valeur choisi dans chaque cellules du tableau
        void swap(array tab1, array tab2);      //échange les valeurs des deux tableaux
        array fusion(array tab1, array tab2);   //fusionne 2 tableaux
        array subset(array entry, array retour,int start, int length);   //crée un nouveau tableau avec les valeurs entre start et start + length et le met dans le tableau retour
        int begin();                    //retourne un iterateur au début du tableau
        int cbegin();                   //retourne un iterateur constant au début du tableau
        int end(array tab);             //retourne un iterateur a la fin du tableau
        int cend(array tab);            //retourne un iterateur constant a la fin du tableau
    };
    Array::Array()
    {

    }
    Array::size(array tab){
        int size = 0;
        //int size = tab.length()
        return size;
    }
    Array::empty(array tab){
        /*if (tab is empty())
        {
            return true
        }
        */
        return false;
    }
    Array::front(array tab){
        return 1;
    }
    Array::back(array tab){
        return 1;
    }
    Array::swap(array tab1, array tab2){

    }
    Array::fusion(array tab1, array tab2){}
    Array::subset(array entry, array retour, int start, int length){}
    Array::fill(volatile value, array tab){
        /*for (int i = 0; i < tab.length; i++)
        {
            tab[i] = value
        }*/
    }
    Array::begin(){
        return 0;
    }
    Array::cbegin(){
        const int i = 0;
        return i;
    }
    Array::end(array tab){
        return 101;
    }
    Array::cend(array tab){
        return 102;
    }
    
}
