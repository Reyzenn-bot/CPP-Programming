ផ្ទុកទិន្នន័យក្នុងឯកសារ : 
    ofstream ofs("file name.txt");
    ofs << "data to write to file";
or  ofs.put('c');
    ofs.close();

ទាញទិន្នន័យពីឯកសារ :
    ifstream ifs("file name.txt");
    ifs >> varname;
or  getline(ifs, varname);
or  ifs.get(varname);