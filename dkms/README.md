# DKMS

dynamic kernel module support


```
                                                  uninstall
                                             ┌─────────────────────┐
                                             │                     │
                                             ▼                     │
┌───────────┐     ┌─────────────┐     ┌────────────┐         ┌─────┴──────┐
│  Not In   │ add │    Added    │build│   Build    │ install │ Installed  │
│   Tree    ├────►│    State    ├────►│   State    ├────────►│  State     │
│           │     │             │     │            │         │            │
└───────────┘     └─────────────┘     └────────────┘         └─────┬──────┘
      ▲                                                            │
      │                                                            │
      └────────────────────────────────────────────────────────────┘
                            remove
```


the source folder must under /usr/src/Module-Module-version



```bash
dkms status

sudo dkms add -m hello -v 1.0.0

sudo dkms install -m hello -v 1.0.0

sudo dkms remove -m hello -v 1.0.0 --all
sudo dkms remove hello/1.0.0 -k `uname -r`
```


