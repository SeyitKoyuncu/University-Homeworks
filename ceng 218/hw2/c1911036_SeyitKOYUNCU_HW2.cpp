#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>

using namespace std;

class File
{
    protected:
        string filename;
        double filesize;

    public:
        File() 
        {
            filename = "";
            filesize = 0;
        }

        File(string filename, double filesize)
        {
            this -> filename = filename;
            this -> filesize = filesize;
        }

        virtual void print()
        {
            cout << "file print";
        }
};        

class ImageFile : public File
{   
    private: 
        int width;
        int height;

    public:
        ImageFile() : File()
        {
            width = 0;
            height = 0;
        }

        ImageFile(string filename, double filesize, int width, int height) : File(filename, filesize)
        {
            this -> width = width;
            this -> height = height;
        }

        virtual void print()
        {
            string sizeSit = "KB";
            double kb = filesize * 0.0009765625;
            filesize = kb;
            if(kb > 1000)
            {
                double mb = kb * 0.0009765625;
                sizeSit = "MB";
                filesize = mb;
                if(mb > 1000)
                {
                    double gb = mb * 0.0009765625; 
                    sizeSit = "GB";
                    filesize = gb;
                }
            }

            cout << filename << " is a " << width << "x" << height << " image file " << "(" << filesize << " "<< sizeSit << " )" << endl; 
            return ;
        }
};

class AudioFile : public File
{   
    private:
        int duration;

    public:
    AudioFile() : File()
    {
        duration = 0;
    }

    AudioFile(string filename, double filesize, int duration) : File(filename,filesize)
    {
        this -> duration = duration;
    }

    void print()
    {
            string sizeSit = "KB";
            double kb = filesize * 0.0009765625;
            filesize = kb;
            if(kb > 1000)
            {
                double mb = kb * 0.0009765625;
                sizeSit = "MB";
                filesize = mb;
                if(mb > 1000)
                {
                    double gb = mb * 0.0009765625; 
                    sizeSit = "GB";
                    filesize = gb;
                }
            }

        int min = duration / 60;
        int sec = duration % 60;
        cout << filename << " is a " << min << " minuted " << sec << " seconds " << " long audio file " << "(" << filesize << " "<< sizeSit << " )" << endl; 
    }
};

class DocunentFile : public File
{
    private:
        int nrOfWords;

    public:
        DocunentFile() : File()
        {
            nrOfWords = 0;
        }

        DocunentFile(string filename, double filesize, int nrofwords) : File(filename, filesize)
        {
            this -> nrOfWords = nrofwords;
        }

        void print()
        {   
            string sizeSit = "KB";
            double kb = filesize * 0.0009765625;
            filesize = kb;
            if(kb > 1000)
            {
                double mb = kb * 0.0009765625;
                sizeSit = "MB";
                filesize = mb;
                if(mb > 1000)
                {
                    double gb = mb * 0.0009765625; 
                    sizeSit = "GB";
                    filesize = gb;
                }
            }
            cout << filename << " is a " << nrOfWords << " words " << "long document file " << "(" << filesize << " "<< sizeSit << " )" << endl;        
        }
};  

class VideoFile : public File
{
    private:
        int duration;
        string pixelSize;

    public:
        VideoFile() : File()
        {
            duration = 0;
            pixelSize = " ";
        }

        VideoFile(string filename, int filesize, int duration, string pixelSize) : File(filename, filesize)
        {
            this -> duration = duration;
            this -> pixelSize = pixelSize;
        }

        void print()
        {
            string sizeSit = "KB";
            double kb = filesize * 0.0009765625;
            filesize = kb;
            if(kb > 1000)
            {
                double mb = kb * 0.0009765625;
                sizeSit = "MB";
                filesize = mb;
                if(mb > 1000)
                {
                    double gb = mb * 0.0009765625; 
                    sizeSit = "GB";
                    filesize = gb;
                }
            }

            int min = duration / 60;
            int sec = duration % 60;
            cout << filename << " is a " << min << " minuted " << sec << " seconds " << pixelSize << " long video file " << "(" << filesize << " "<< sizeSit << " )" << endl;     
        }
};


int main()
{
    vector <File*> files;

    ifstream file;

    file.open("testhw2.txt");

    string fileName;
    string typeOfFile;
    double fileSize;
    int count = 0;

    while(!file.eof())
    {
        file >> fileName;
        file >> typeOfFile;
        file >> fileSize;
        
        
        int size = typeOfFile.size();
        for(int i = 0; i < size; i++)
        {
            typeOfFile[i] = tolower(typeOfFile[i]);
         }

        if(typeOfFile == "image")
        {
            int width;
            int height;
            file >> width;
            file >> height;
            ImageFile *imageFile = new ImageFile(fileName, fileSize, width, height);
            files.push_back(imageFile);
            files[count]->print();
            count++;
        }

        else if(typeOfFile == "audio")
        {
            int duration;
            file >> duration;
            AudioFile *audioFile = new AudioFile(fileName, fileSize, duration);
            files.push_back(audioFile);
            files[count]->print();
            count++;            
        }

        else if(typeOfFile == "document")
        {
            int nrOfWords;
            file >> nrOfWords;
            DocunentFile * documentFile = new DocunentFile(fileName, fileSize, nrOfWords);
            files.push_back(documentFile);
            files[count]->print();
            count++;            
        }

        else if(typeOfFile == "video")
        {
            int duration;
            string pixelsize;
            file >> duration;
            file >> pixelsize;
            VideoFile * videoFile = new VideoFile(fileName, fileSize, duration, pixelsize);
            files.push_back(videoFile);
            files[count]->print();
            count++;
        }

        else
        {
            cout << "In this program we dont have any file type like " << fileName;
        }
    }
}