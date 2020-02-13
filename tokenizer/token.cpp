#include <string>
#include <iostream>
#include <fstream>

using std::string;
using std::cout;

int main(int argc, char *argv[])
{
  const string stringlineonly = "--lineonly";    //local variables go here
  bool lineOnly = false;
  string fileName = "";

  switch (argc)                                      //sorts out argument input
  {                                                 //expects ./a.out "filename" (optional)--lineonly
    case 1:                                        //anything more than 3 arguments will exit program
      fileName = "output.txt";                    //if second argument is not --lineonly, it will be ignored
    break;                                       //if there are no arguments "output.txt" is used for output"
    case 2:
      fileName = argv[1];
    break;
    case 3:
      fileName = argv[1];
      if(stringlineonly.compare(argv[2])==0) lineOnly = true;
      else cout<<"unknown argument: "<<argv[2]<<", ignoring..."<<"\n";
    break;
    default:
      cout<<"Too many arguments, exiting...";
    return 1;
  }
  if(!(fileName[fileName.length() - 4] == '.'))     //makes sure the first argument is a filename
  {                                                //otherwise, program will exit before making any file streams
    cout<<fileName<<" is not a filename, exiting...\n";
    return 1;
  }


  cout<<"argc:"<<argc<<"\n";                           //debug output
  for(int i=0;i<argc;i++) cout<<i<<":"<<argv[i]<<"\n";
  cout<<"lineOnly:"<<lineOnly<<"\n";
  cout<<"filename:"<<fileName<<"\n";
  return 0;
}
