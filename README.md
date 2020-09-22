# inspect_hw_logs
This code base is used to inspect the text log files extracted from the book builder of FPGA. 
To compile te project simply run 
```
cd ./build
cmake ..
```
After a successfull compilation you must have the binary `./build/run`. To run the binary with mbo and mbp log files, for example, supposing that you are at `build` directory,

```
mkdir ../out
./run ../data/bb_200917_1.log ../data/mbpu_200917_1.log > ./out/res_200917_1.txt
```
will be sufficient. The output will be in the following `csv` format:

```
7162397422582759495, 0, 1, 2
7162397422582659498, 0, 0, 2
7162397422582747444, 0, 0, 2
7162397422577053031, 0, 0, 2
7162397422581831216, 0, 0, 2
7162397422577048449, 0, 0, 2
7162397422582733739, 0, 0, 2
7162397422582742048, 0, 0, 2
7162397422582640618, 0, 0, 2
7162397422576621487, 0, 0, 2
...
```
