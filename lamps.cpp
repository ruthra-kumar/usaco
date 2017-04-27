#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>

using namespace std;

long long int n,c;
vector< vector<int> > states;
vector<int> on,off;
vector< vector<bool> > lamp_collection;

bool cmp(const vector<bool> &a,const vector<bool> &b){

  if(a.size() != b.size() ) return false;

  for(unsigned int i=0;i < a.size() ;i++){
    if(a[i] < b[i] ){
      return true;
    }
    else if(a[i] > b[i]){
      return false;
    }
  }

  return true;
}

bool Present(vector<bool> current_lamp){
  bool found = false;
  for(unsigned int i=0;i<lamp_collection.size();){

    //for each lamp
    unsigned int j;
    for(j=0;j<lamp_collection[i].size();){
      if(current_lamp[j] == lamp_collection[i][j]){
	j++;
      }
      else{
	break;
      }
    }
    if(j == current_lamp.size()){
      found = true;
      break;
    }
    
  }
  return found;
}

void Process_states(vector<int> cur_state){

  vector<bool> lamps(n,1);

  //Initialize the lamps
  /*    for(int z=0;z<n;z++){
	lamps[z] = 1;
	}
  */

  for(unsigned int j=0;j<cur_state.size();j++){

    switch(cur_state[j]){
    case 1:
      //Button 1 pressed
      for(int i=0;i<n;i++){
	lamps[i] = !lamps[i];
      }
      break;

    case 2:
      //if button 2 pressed
      for(int i=1;i<=n;i+=2){
	lamps[i-1] = !lamps[i-1];
      }
      break;

    case 3:
      //if button 3 pressed
      for(int i=2;i<=n;i+=2){
	lamps[i-1] = !lamps[i-1];
      }
      break;

    case 4:
      //if button 4 is pressed
      for(int K=0; K <= n; K++){
	lamps[ (3*K)] = !lamps[ (3*K) ];
      }
      break;
    default:break;
    }
  }

  bool on_states = true, off_states = true;
  //check if all on lamps from final state is present
  for(unsigned int x=0; x<on.size(); x++){
    if(lamps[ on[x] ] != 1){
      on_states = false;
    }
  }
  //check if all off lamps from final state is present
  for(unsigned int x=0; x<off.size(); x++){
    if(lamps[ (off[x]-1) ] != 0){
      off_states = false;
    }
  }

  /*
    for(unsigned int x = 0 ; x < lamps.size() ; x++ ){
    cout << lamps[x];
    }
    cout << '\n';
  */
  //if current lamp configuration matches the requirement
  if( on_states && off_states ){
    //check if a copy is already present
    if(Present(lamps) == false){
      lamp_collection.push_back(lamps);
    }
  }
}

void Generate(long long int C,vector<int> sc){

  if(C > 0){

    for(long long int current_option = 1; current_option <= 4; current_option++){
      vector<int> cpy(sc);
      if(cpy.empty() == false){
	if(current_option != cpy.back()){
	  cpy.push_back(current_option);
	}
	Generate(C-1,cpy);
      }
      else{
	cpy.push_back(current_option);
	Generate(C-1,cpy);
      }
    }
  }
  else{
    //once state is created, generate the required lamp configuration
    //states.push_back(sc);
    Process_states(sc);
  }
}

int main(){

  cin >> n >> c;

  int num;

  cin >> num;

  //save all the on of final state

  while(num != -1){
    on.push_back(num);
    cin >> num;
  }

  //save all the off of final state

  cin >> num;

  while(num != -1){
    off.push_back(num);
    cin >> num;
  }

  //generate all possible states
  vector<int> state_change;

  Generate(c,state_change);

  //Cleanup();
  /*
  for(unsigned int i=0;i<states.size();i++){
    for(unsigned int j=0;j<states[i].size();j++){
      cout << states[i][j] << " ";
    }
    cout << '\n';
  }
  */

  /*
  for(unsigned int i=0;i<states.size();i++){
    for(unsigned int j=0;j<states[i].size();j++){
      cout << states[i][j] << " ";
    }
    cout << '\n';
  }
  */
  cout << lamp_collection.size() << '\n';
  cout << "Sorting \n";
  sort(lamp_collection.begin(),lamp_collection.end(),cmp);
  cout << "Sorting done\n";
  for(unsigned int i=0; i < lamp_collection.size() ; i++){
    for(unsigned int j=0; j < lamp_collection[i].size(); j++){
      cout << lamp_collection[i][j];
    }
    cout << '\n';
  }


  return 0;
}
