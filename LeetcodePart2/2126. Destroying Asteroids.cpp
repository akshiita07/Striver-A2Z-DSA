class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        // original mass of planet
        //ast[i]=mass of ast i
        // mass planet >= mass ast: ast destroyed & planet mass+=ast mass
        // else mass planet< mass ast: planet destroyed
        // true if all asteroids can be destroyed
        sort(asteroids.begin(),asteroids.end());
        int n=asteroids.size();
        long long planetMass=mass;
        for(int i=0;i<n;i++){
            if(planetMass>=asteroids[i]){
                planetMass+=asteroids[i];
            }else{
                return false;
            }
        }
        return true;
    }
};
