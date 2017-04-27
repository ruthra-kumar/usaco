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


void Generate(long long int C,vector<int> sc){

  if(C > 0){

    for(long long int current_option = 1; current_option <= 4; current_option++){
      vector<int> cpy(sc);
      cpy.push_back(current_option);
      Generate(C-1,cpy);
    }
  }
  else{
    states.push_back(sc);
  }
}

long long int Getint(vector<int> current_state){
  long long int num = 0;
  long long int mul = 1;

  for(int i = current_state.size()-1; i>= 0 ;i--){
    num += (mul * current_state[i]);
    mul *= 10;
  }

  return num;
}

void Cleanup(){
  vector< vector<int> > states_copy;

  //removes commutative elements
  for(unsigned int i=0; i < states.size(); i++){

    //    cout << "Stage 1 "<< '\n';
    stack<int> s;
    for(long long int j=states[i].size()-1; j >= 0; j--){
      if(s.empty() == false){
	if( s.top() != states[i][j] ){
	  s.push(states[i][j]);
	}
	else{
	  s.pop();
	}
      }
      else{
	s.push(states[i][j]);
      }
    }

    //    cout << "Stage 3 "<< '\n';
    //store in cleaned up states
    if(s.empty() == false){
      vector<int> tmp;
      while(s.empty() != true){
	tmp.push_back(s.top());
	s.pop();
      }

      states_copy.push_back(tmp);
    }
  }

  vector<long long int> sequence;

  //remove old entries
  states.clear();
  
  for(long long int i=0;i<states_copy.size(); i++){

    long long int prod = Getint(states_copy[i]);

    if(find(sequence.begin(),sequence.end(),prod) == sequence.end()){
      sequence.push_back(prod);
      states.push_back(states_copy[i]);
    }
    
  }
}

void Process_states(){
  for(unsigned int c_state=0;c_state<states.size();c_state++){
    //for each state
    
    vector<bool> lamps(n,1);

    //Initialize the lamps
    /*    for(int z=0;z<n;z++){
      lamps[z] = 1;
    }
    */

    for(unsigned int j=0;j<states[c_state].size();j++){
      
      switch(states[c_state][j]){
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
    
    if( on_states && off_states ){
      lamp_collection.push_back( lamps );
    }
    
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

  Cleanup();
  /*    
  for(unsigned int i=0;i<states.size();i++){
    for(unsigned int j=0;j<states[i].size();j++){
      cout << states[i][j] << " ";
    }
    cout << '\n';
  }
  */

  Process_states();
  /*
  for(unsigned int i=0;i<states.size();i++){
    for(unsigned int j=0;j<states[i].size();j++){
      cout << states[i][j] << " ";
    }
    cout << '\n';
  }
  */
  cout << lamp_collection.size() << '\n';
  //  cout << "Sorting \n";
  sort(lamp_collection.begin(),lamp_collection.end(),cmp);
  //  cout << "Sorting done\n";
  for(unsigned int i=0; i < lamp_collection.size() ; i++){
    for(unsigned int j=0; j < lamp_collection[i].size(); j++){
      cout << lamp_collection[i][j];
    }
    cout << '\n';
  }
  

  return 0;
}
