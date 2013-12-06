/****************************************************************************
**
** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the utility applications of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Digia gives you certain additional
** rights.  These rights are described in the Digia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3.0 as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 3.0 requirements will be
** met: http://www.gnu.org/copyleft/gpl.html.
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef PMMAPPERVIEW_H
#define PMMAPPERVIEW_H


//  INCLUDES
#include <aknview.h>
#include <EIKLBO.H>

// CONSTANTS
// FORWARD DECLARATIONS
class CAknSingleStyleListBox;
class CAknSettingStyleListBox;

// CLASS DECLARATION

/**
*  CPixelMetricsMapperViewContainer
*
*/
class CPixelMetricsMapperViewContainer
:   public CCoeControl,
    public MCoeControlObserver
    {
    public:  // Constructors and destructor

        /**
        * C++ constructor.
        */
    	CPixelMetricsMapperViewContainer();

        /**
        * Symbian 2nd phase constructor.
        *
        * @param aRect Rectangle.
        */
        void ConstructL( const TRect& aRect );

        /**
        * Destructor.
        */
        ~CPixelMetricsMapperViewContainer();


    public: // New functions

        /**
        * Show the given string.
        *
        * @param aString The string to be shown.
        */
        void ShowL( const TDesC& aString, TBool& aLast, const TBool& aFileOutput = EFalse );

        void ClearL();


    public:  // Functions from base classes

        /**
        * From CCoeControl.
        */
        TKeyResponse OfferKeyEventL(
            const TKeyEvent& aKeyEvent,
            TEventCode aType );


        void HandleResourceChange(TInt aType);


    private:  // Functions from base classes

        /**
        * From CCoeControl.
        */
        void SizeChanged();

        /**
        * From CCoeControl.
        */
        TInt CountComponentControls() const;

        /**
        * From CCoeControl.
        */
        CCoeControl* ComponentControl( TInt aIndex ) const;

        /**
        * From CCoeControl.
        */
        void Draw( const TRect& aRect ) const;


    private:  // Functions from base classes

        /**
        * From MCoeControlObserver.
        */
        void HandleControlEventL(
            CCoeControl* aControl,
            TCoeEvent aEventType );


    private:    // Data

        // Texts.
        CDesCArray*                 iTexts;

        // Count.
        TInt                        iCount;

        // Listbox.
        CAknSingleStyleListBox*     iListbox;

    };



/**
*  CPixelMetricsMapperView
*
*
*  @since 1.0
*/
class CPixelMetricsMapperView : public CAknView
    {
    public:  // Constructors and destructor

        /**
        * Symbian 2nd phase constructor.
        */
        void ConstructL();

        /**
        * Destructor.
        */
        ~CPixelMetricsMapperView();


    public: // Functions from base classes

        /**
        * From CAknView.
        */
        TUid Id() const;

        /**
        * From CAknView.
        */
        void HandleCommandL( TInt aCommand );

        /**
        * From CAknView.
        */
        void HandleStatusPaneSizeChange();

        /**
        * From CAknView.
        */
        void ShowL( const TDesC& aString, TBool& aLast, const TBool& aFileOutput =EFalse );
        void ClearL();


    private: // from CAknView

        /**
        * From CAknView.
        */
        void DoActivateL(
            const TVwsViewId& aPrevViewId,
            TUid aCustomMessageId,
            const TDesC8& aCustomMessage );

        /**
        * From CAknView.
        */
        void DoDeactivate();


    private:    // Data

        // The view container.
        CPixelMetricsMapperViewContainer*    iView;

    };

#endif // PMMAPPERVIEW_H

// End of File
