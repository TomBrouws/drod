// $Id$

/* ***** BEGIN LICENSE BLOCK *****
 * Version: MPL 1.1
 *
 * The contents of this file are subject to the Mozilla Public License Version
 * 1.1 (the "License"); you may not use this file except in compliance with
 * the License. You may obtain a copy of the License at
 * http://www.mozilla.org/MPL/
 *
 * Software distributed under the License is distributed on an "AS IS" basis,
 * WITHOUT WARRANTY OF ANY KIND, either express or implied. See the License
 * for the specific language governing rights and limitations under the
 * License.
 *
 * The Original Code is Deadly Rooms of Death.
 *
 * The Initial Developer of the Original Code is
 * Caravel Software.
 * Portions created by the Initial Developer are Copyright (C) 1995, 1996, 
 * 1997, 2000, 2001, 2002, 2005 Caravel Software. All Rights Reserved.
 *
 * Contributor(s):
 * Mike Rimer (mrimer)
 *
 * ***** END LICENSE BLOCK ***** */

//Class for handling wubba monster game logic.

#ifndef WUBBA_H
#define WUBBA_H

#include "Monster.h"
#include "MonsterFactory.h"

class CWubba : public CMonster
{
public:
	CWubba(CCurrentGame *pSetCurrentGame = NULL) : CMonster(M_WUBBA, pSetCurrentGame)
		, wNextStabTurn(0) {}
	IMPLEMENT_CLONE_REPLICATE(CMonster, CWubba);

	virtual bool CheckForDamage(CCueEvents& CueEvents);
	virtual bool DoesSquareContainObstacle(const UINT wCol, const UINT wRow) const;
	virtual bool IsAggressive() const {return false;}
	virtual bool OnStabbed(CCueEvents &CueEvents, const UINT wX=-1, const UINT wY=-1,
			WeaponType weaponType=WT_Sword);
	virtual void Process(const int nLastCommand, CCueEvents &CueEvents);

private:
	UINT wNextStabTurn;
};

#endif //...#ifndef WUBBA_H