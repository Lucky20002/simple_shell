#!/bin/bash

# Generates the authors file listing contributors to the repository

{
	cat <<- 'EOH'
#this file listd all the individual who have contributed to this repository
# For how it is generated, see 'generateAUTHORS'
		EOH
		echo
		git log --format='%aN <%aE>' | LC_ALL=C.UTF-8 sort -uf
} > AUTHORS
