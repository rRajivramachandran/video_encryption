#include <cryptopp/modes.h>
#include <bits/stdc++.h>
#include <iostream>

using std::cout;
using std::cerr;
using std::endl;

#include <string>
using std::string;

#include <cstdlib>
using std::exit;

#include "cryptlib.h"
using CryptoPP::Exception;

#include "hex.h"
using CryptoPP::HexEncoder;
using CryptoPP::HexDecoder;

#include "filters.h"
using CryptoPP::StringSink;
using CryptoPP::StringSource;
using CryptoPP::StreamTransformationFilter;

#include "crypto++/sha.h"
using namespace std;

int main()
{
    byte h[32];
    CryptoPP::SHA256 hash;
    byte digest2[32],chunk[1024],chunkcrap[1056]; 
    byte a;
    float counter=0;
    int i,j;
    string output;
    int count=0,p,q,k,r;
    ifstream f1;
    CryptoPP::HexEncoder encoder;
    f1.open("6.1.intro.mp4");
    f1.seekg(0,ios::end);
    p=f1.tellg()/1024;
    q=f1.tellg()%1024;
    f1.close();
    j=p;
    byte chunky[q];
    if(q==0)
    	{
    		r=p-1;
    		j=p-1;
    	}
    else
    	{
    		r=p;
    		j=p;
         }
    byte hashes[r][32];
    ofstream f2;
    f2.open("hashes.txt",ios::trunc);
    while(j>=0)
    {
     	   f1.open("6.1.intro.mp4");

           for(i=1;i<=j;i++)
           	f1.read((char*)&chunk,sizeof(chunk));
           if(j==p)
            {
            	f1.read((char*)&chunky,sizeof(chunky));
            	hash.CalculateDigest( digest2, (byte*)chunky, q);
            	
                
            }
            else
            {   
            	for(i=0;i<32;i++)
            	hashes[r][i] = digest2[i];
            	f1.read((char*)&chunk,sizeof(chunk));
                int k;
                for(k=0;k<1024;k++)
           	       chunkcrap[k]=chunk[k]; 
           	    for(k=1024;k<1056;k++) 
                    chunkcrap[k]=digest2[k-1024];
                hash.CalculateDigest( digest2, (byte*)chunkcrap, 1056);
                r--;
            }

           j--;
           
          f1.close();

            

     }
for(i=0;i<32;i++)
    hashes[r][i] = digest2[i];

encoder.Attach( new CryptoPP::StringSink( output ) );
if(q==0)
{
    for(i=0;i<p;i++)
    {

      output="";
      encoder.Put( hashes[i], sizeof(hashes[i]) );
      
      
      f2<<"hash of block no";
      f2<<i;
      f2<<"is:";
      f2<<output;
      f2<<"\n";
     
    }
}
else
	for(i=0;i<p+1;i++)
    {

      output="";
      encoder.Put( hashes[i], sizeof(hashes[i]) );
      
      
      f2<<"hash of block no";
      f2<<i;
      f2<<"is:";
      f2<<output;
      f2<<"\n";
      
    }

f2.close();
cout<<"hashing done";
}
