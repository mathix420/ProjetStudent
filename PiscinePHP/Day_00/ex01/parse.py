# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    parse.py                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agissing <agissing@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/21 13:50:34 by agissing          #+#    #+#              #
#    Updated: 2019/03/21 14:03:20 by agissing         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

f = open("data.csv", "r")

data = f.read()

types=[]

#atomicNumber, symbol, name, atomicMass, cpkHexColor, electronicConfiguration, electronegativity, atomicRadius, ionRadius, vanDelWaalsRadius, ionizationEnergy, electronAffinity, oxidationStates, standardState, bondingType, meltingPoint, boilingPoint,density, groupBlock, yearDiscovered

atoms = [i.replace(' ', '').split(',') for i in data.split('\n')];

firstrow = range(57,72)
secondrow = range(89,104)

for atom in atoms:
    classnames = atom[-2]
    if atom[-2] not in types:
        types.append(atom[-2])
    if int(atom[0]) in firstrow:
        classnames += ' first-row'
    elif int(atom[0]) in secondrow:
        classnames += ' second-row'
    print('''<div class="card {}">
    <h3>{}</h3>
    <h1>{}</h1>
    <h5>{}</h5>
</div>'''.format(classnames, atom[0], atom[1], atom[3]))


print(types)
