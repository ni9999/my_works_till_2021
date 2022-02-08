# Simulate a sports tournament

import csv
import sys
import random

# Number of simluations to run
N = 1000


def main():

    # Ensure correct usage
    if len(sys.argv) != 2:
        sys.exit("Usage: python tournament.py FILENAME")

    teams = []
    # TODO: Read teams into memory from file
    i=0
    with open(f"{sys.argv[1]}") as csvfile:
        reader = csv.DictReader(csvfile)
        for row in reader:
            teams.append(row)
            teams[i]["rating"]=int(teams[i]["rating"])
            i=i+1

    counts = {}
    # TODO: Simulate N tournaments and keep track of win counts
    for i in range(0,len(teams),1):
        team_name = teams[i]["team"]
        counts[f"{team_name}"] = 0
    for i in range(0,N,1):
        win = simulate_tournament(teams)
        team_name = win[0]["team"]
        counts[f"{team_name}"] += 1
        
    print ()
    # Print each team's chances of winning, according to simulation
    for team in sorted(counts, key=lambda team: counts[team], reverse=True):
        print(f"{team}: {counts[team] * 100 / N:.1f}% chance of winning")


def simulate_game(team1, team2):
    """Simulate a game. Return True if team1 wins, False otherwise."""
    rating1 = team1["rating"]
    rating2 = team2["rating"]
    probability = 1 / (1 + 10 ** ((rating2 - rating1) / 600))
    return random.random() < probability

# probably sloppy code written. cz here this function always taking input teams and probably working all the way. 
#better def simulate_round (win)
def simulate_round(teams):
    """Simulate a round. Return a list of winning teams."""
    winners = []

    # Simulate games for all pairs of teams
    for i in range(0, len(teams), 2):
        if simulate_game(teams[i], teams[i + 1]):
            winners.append(teams[i])
        else:
            winners.append(teams[i + 1])

    return winners


def simulate_tournament(teams):
    """Simulate a tournament. Return name of winning team."""
    # TODO
    win = simulate_round(teams)
    while len(win)>1:
        win = simulate_round(win)
    return win
    
if __name__ == "__main__":
    main()
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
