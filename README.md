# Caisse v0.0.2 - C++ (11^) library
This serves as a general purpose library that will emulate some of the standard library containers but with less
functionality. However, the library will aim to be as production ready as possible.

This mainly serves as C++ practice, but hopefully can be built into a useful library in the future.

In order to use in your project, move the /zmc directory into your desired file-system location and include the header file
zmc/caisse.h

---
## Containers
### zmc::vector<<T>T> - Contiguous memory managed array of generic elements 
### zmc::pair<<T>T1, T2> - Pair structure for two generic data types 
### zmc::string - Contiguous memory managed array of characters
### zmc::forward_list<<T>T> - Node based singly-linked list of generic elements
  
---
## Repository Git Protocol - Git Flow
In order to contribute to this repository, use the git cli, GUI based git clients with support for git flow (such as gitkraken) or use the corresponding commands
with the vanilla git cli. I did not create this guide myself. It was taken from another [git repository](https://gist.github.com/JamesMGreene/cdd0ac49f90c987e45ac) by user [JamesMGreene](https://gist.github.com/JamesMGreene)
### Initialize

gitflow | git
--------|-----
`git flow init` | `git init`
&nbsp; | `git commit --allow-empty -m "Initial commit"`
&nbsp; | `git checkout -b develop master`


### Connect to the remote repository

gitflow | git
--------|-----
_N/A_ | `git remote add origin git@github.com:MYACCOUNT/MYREPO`


### FEATURES

### Create a feature branch

gitflow | git
--------|-----
`git flow feature start MYFEATURE` | `git checkout -b feature/MYFEATURE develop`


### Share a feature branch

gitflow | git
--------|-----
`git flow feature publish MYFEATURE` | `git checkout feature/MYFEATURE`
&nbsp; | `git push origin feature/MYFEATURE`


### Get latest for a feature branch

gitflow | git
--------|-----
`git flow feature pull origin MYFEATURE` | `git checkout feature/MYFEATURE`
&nbsp; | `git pull --rebase origin feature/MYFEATURE`


### Finalize a feature branch

gitflow | git
--------|-----
`git flow feature finish MYFEATURE` | `git checkout develop`
&nbsp; | `git merge --no-ff feature/MYFEATURE`
&nbsp; | `git branch -d feature/MYFEATURE`


### Push the merged feature branch

gitflow | git
--------|-----
_N/A_ | `git push origin develop`
&nbsp; | `git push origin :feature/MYFEATURE` _(if pushed)_


### RELEASES

### Create a release branch

gitflow | git
--------|-----
`git flow release start 1.2.0` | `git checkout -b release/1.2.0 develop`


### Share a release branch

gitflow | git
--------|-----
`git flow release publish 1.2.0` | `git checkout release/1.2.0`
&nbsp; | `git push origin release/1.2.0`


### Get latest for a release branch

gitflow | git
--------|-----
_N/A_ | `git checkout release/1.2.0`
&nbsp; | `git pull --rebase origin release/1.2.0`


### Finalize a release branch

gitflow | git
--------|-----
`git flow release finish 1.2.0` | `git checkout master`
&nbsp; | `git merge --no-ff release/1.2.0`
&nbsp; | `git tag -a 1.2.0`
&nbsp; | `git checkout develop`
&nbsp; | `git merge --no-ff release/1.2.0`
&nbsp; | `git branch -d release/1.2.0`


### Push the merged feature branch

gitflow | git
--------|-----
_N/A_ | `git push origin master`
&nbsp; | `git push origin develop`
&nbsp; | `git push origin --tags`
&nbsp; | `git push origin :release/1.2.0` _(if pushed)_


### HOTFIXES

### Create a hotfix branch

gitflow | git
--------|-----
`git flow hotfix start 1.2.1 [commit]` | `git checkout -b hotfix/1.2.1 [commit]`


### Finalize a hotfix branch

gitflow | git
--------|-----
`git flow hotfix finish 1.2.1` | `git checkout master`
&nbsp; | `git merge --no-ff hotfix/1.2.1`
&nbsp; | `git tag -a 1.2.1`
&nbsp; | `git checkout develop`
&nbsp; | `git merge --no-ff hotfix/1.2.1`
&nbsp; | `git branch -d hotfix/1.2.1`


### Push the merged hotfix branch

gitflow | git
--------|-----
_N/A_ | `git push origin master`
&nbsp; | `git push origin develop`
&nbsp; | `git push origin --tags`
&nbsp; | `git push origin :hotfix/1.2.1` _(if pushed)_



### References

 - http://nvie.com/posts/a-successful-git-branching-model/
 - https://help.github.com/articles/using-pull-requests#shared-repository-model
