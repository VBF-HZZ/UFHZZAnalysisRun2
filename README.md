# HZZ Analyzer for CMS Run2

## To install:

```bash
cmsrel CMSSW_10_2_15
cd CMSSW_10_2_15/src
cmsenv

git cms-init
git config merge.renameLimit 999999
git clone -b tmp_Ferrico https://github.com/VBF-HZZ/UFHZZAnalysisRun2.git

cp UFHZZAnalysisRun2/install.sh .
./install.sh

cp UFHZZAnalysisRun2/Utilities/crab/* .
```

---

## Notes on using the Analyzer:
Run the Analyzer **locally** before submitting any jobs to CRAB:
```bash
cmsRun UFHZZAnalysisRun2/UFHZZ4LAna/python/<template_file>.py
```

If you want to submit CRAB jobs for processing, first do:
```bash
voms-proxy-init --valid=168:00    #probably need "voms-proxy-init -voms cms -rfc"
source /cvmfs/cms.cern.ch/crab3/crab.sh
```

To process **Data**: 
```python 
python SubmitCrabJobs.py -t "myTask_Data" -d datasets_2016ReReco.txt -c UFHZZAnalysisRun2/UFHZZ4LAna/python/templateData_80X_M1703Feb_2l_cfg.py
```

To process **MC**: 
```python
python SubmitCrabJobs.py -t "myTask_MC" -d datasets_Summer16_25ns_MiniAOD.txt -c UFHZZAnalysisRun2/UFHZZ4LAna/python/templateMC_80X_M17_4l_cfg.py
```

You can use **manageCrabTask.py** to check the status, resubmit, or kill your task. E.g. after submitting, do:
```bash
nohup python -u manageCrabTask.py -t resultsAna_Data_M17_Feb19 -r -l >& managedata.log &
```

This will start an infinite loop of running crab resubmit on all of your tasks, then sleep for 30min. You should kill the process once all of your tasks are done. Once all of your tasks are done, you should run the following command to purge your crab cache so that it doesn't fill up:
```bash
python manageCrabTask.py -t resultsAna_Data_M17_Feb19 -p

UFHZZ4LAna/python/templateMC_102X_Legacy16_4l_cfg.py
UFHZZ4LAna/python/templateMC_102X_Legacy17_4l_cfg.py
UFHZZ4LAna/python/templateMC_102X_Legacy18_4l_cfg.py
UFHZZ4LAna/python/templateData_102X_Legacy16_3l_cfg.py
UFHZZ4LAna/python/templateData_102X_Legacy17_3l_cfg.py
UFHZZ4LAna/python/templateData_102X_Legacy18_3l_cfg.py
```
