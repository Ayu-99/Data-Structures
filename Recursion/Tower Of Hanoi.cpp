void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    // Write your code here
    if(n==0){ //base case
        return;
    }
    towerOfHanoi(n-1, source, destination,  auxiliary); // 1.source to helper using destination 
    cout<<source<<" "<<destination<<endl; //2. Move nth disc from source to destination
    towerOfHanoi(n-1, auxiliary,  source, destination); //3. n-1 from helper to destination using the source
}
  
