    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 11;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc paramMap
        ;%
        paramMap.nSections           = nTotSects;
        paramMap.sectIdxOffset       = sectIdxOffset;
            paramMap.sections(nTotSects) = dumSection; %prealloc
        paramMap.nTotData            = -1;

        ;%
        ;% Auto data (flightControlSystem_P)
        ;%
            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% flightControlSystem_P.CompareToConstant1_const
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_P.CompareToConstant_const
                    section.data(2).logicalSrcIdx = 5;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% flightControlSystem_P.RateTransition_1_InitialCondition
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_P.RateTransition_2_InitialCondition
                    section.data(2).logicalSrcIdx = 7;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_P.RateTransition_3_InitialCondition
                    section.data(1).logicalSrcIdx = 8;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% flightControlSystem_P.FlightControlSystem.CompareToConstant_const
                    section.data(1).logicalSrcIdx = 9;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_P.FlightControlSystem.CompareToConstant1_const
                    section.data(2).logicalSrcIdx = 10;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_P.FlightControlSystem.CompareToConstant2_const
                    section.data(3).logicalSrcIdx = 11;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_P.FlightControlSystem.Memory1_InitialCondition
                    section.data(1).logicalSrcIdx = 12;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% flightControlSystem_P.FlightControlSystem.UnitDelay_InitialCondition
                    section.data(1).logicalSrcIdx = 13;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_P.FlightControlSystem.Constant3_Value
                    section.data(2).logicalSrcIdx = 14;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_P.FlightControlSystem.Constant1_Value
                    section.data(1).logicalSrcIdx = 15;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(7) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%

                        ;% Sensors
                        section.nData = 1;
                        section.data(1).logicalSrcIdx = 0;
                        section.data(1).dtTransOffset = 0;

                        nTotData = nTotData + section.nData;
                        paramMap.sections(8) = section;
                        clear section


                        ;% landingAltitude
                        section.nData = 1;
                        section.data(1).logicalSrcIdx = 1;
                        section.data(1).dtTransOffset = 0;

                        nTotData = nTotData + section.nData;
                        paramMap.sections(9) = section;
                        clear section


                        ;% measurementTolerance
                        section.nData = 1;
                        section.data(1).logicalSrcIdx = 2;
                        section.data(1).dtTransOffset = 0;

                        nTotData = nTotData + section.nData;
                        paramMap.sections(10) = section;
                        clear section


                        ;% enableLanding
                        section.nData = 1;
                        section.data(1).logicalSrcIdx = 3;
                        section.data(1).dtTransOffset = 0;

                        nTotData = nTotData + section.nData;
                        paramMap.sections(11) = section;
                        clear section



        ;%
        ;% Add final counts to struct.
        ;%
        paramMap.nTotData = nTotData;



    ;%**************************
    ;% Create Block Output Map *
    ;%**************************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 8;
        sectIdxOffset = 0;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc sigMap
        ;%
        sigMap.nSections           = nTotSects;
        sigMap.sectIdxOffset       = sectIdxOffset;
            sigMap.sections(nTotSects) = dumSection; %prealloc
        sigMap.nTotData            = -1;

        ;%
        ;% Auto data (flightControlSystem_B)
        ;%
            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% flightControlSystem_B.dy
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_B.dx
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_B.deltaX
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% flightControlSystem_B.deltaY
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% flightControlSystem_B.bottom
                    section.data(1).logicalSrcIdx = 4;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_B.top
                    section.data(2).logicalSrcIdx = 5;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% flightControlSystem_B.circle
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_B.Submatrix
                    section.data(2).logicalSrcIdx = 7;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_B.Submatrix1
                    section.data(3).logicalSrcIdx = 8;
                    section.data(3).dtTransOffset = 901;

                    ;% flightControlSystem_B.circle_e
                    section.data(4).logicalSrcIdx = 9;
                    section.data(4).dtTransOffset = 1801;

                    ;% flightControlSystem_B.y
                    section.data(5).logicalSrcIdx = 10;
                    section.data(5).dtTransOffset = 1802;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% flightControlSystem_B.FlightControlSystem.Grabber
                    section.data(1).logicalSrcIdx = 11;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_B.FlightControlSystem.grabber_c
                    section.data(2).logicalSrcIdx = 21;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_B.FlightControlSystem.landing_flag
                    section.data(3).logicalSrcIdx = 22;
                    section.data(3).dtTransOffset = 2;

                    ;% flightControlSystem_B.FlightControlSystem.takeoff_flag
                    section.data(4).logicalSrcIdx = 23;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            sigMap.sections(4) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_B.FlightControlSystem.Abs
                    section.data(1).logicalSrcIdx = 24;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(5) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% flightControlSystem_B.FlightControlSystem.x_g
                    section.data(1).logicalSrcIdx = 25;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_B.FlightControlSystem.y_b
                    section.data(2).logicalSrcIdx = 26;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_B.FlightControlSystem.z_g
                    section.data(3).logicalSrcIdx = 27;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            sigMap.sections(6) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% flightControlSystem_B.FlightControlSystem.Compare
                    section.data(1).logicalSrcIdx = 28;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_B.FlightControlSystem.Compare_d
                    section.data(2).logicalSrcIdx = 29;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_B.FlightControlSystem.Compare_dd
                    section.data(3).logicalSrcIdx = 30;
                    section.data(3).dtTransOffset = 2;

                    ;% flightControlSystem_B.FlightControlSystem.stable
                    section.data(4).logicalSrcIdx = 31;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            sigMap.sections(7) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%

                        ;% motors_outport
                        section.nData = 1;
                        section.data(1).logicalSrcIdx = 50;
                        section.data(1).dtTransOffset = 0;

                        nTotData = nTotData + section.nData;
                        sigMap.sections(8) = section;
                        clear section



        ;%
        ;% Add final counts to struct.
        ;%
        sigMap.nTotData = nTotData;



    ;%*******************
    ;% Create DWork Map *
    ;%*******************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 11;
        sectIdxOffset = 8;

        ;%
        ;% Define dummy sections & preallocate arrays
        ;%
        dumSection.nData = -1;
        dumSection.data  = [];

        dumData.logicalSrcIdx = -1;
        dumData.dtTransOffset = -1;

        ;%
        ;% Init/prealloc dworkMap
        ;%
        dworkMap.nSections           = nTotSects;
        dworkMap.sectIdxOffset       = sectIdxOffset;
            dworkMap.sections(nTotSects) = dumSection; %prealloc
        dworkMap.nTotData            = -1;

        ;%
        ;% Auto data (flightControlSystem_DW)
        ;%
            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% flightControlSystem_DW.RateTransition_1_Buffer
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_DW.RateTransition_2_Buffer
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            dworkMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_DW.Scope_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% flightControlSystem_DW.RateTransition_1_ActiveBufIdx
                    section.data(1).logicalSrcIdx = 8;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_DW.RateTransition_2_ActiveBufIdx
                    section.data(2).logicalSrcIdx = 9;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% flightControlSystem_DW.is_active_c8_flightControlSystem
                    section.data(1).logicalSrcIdx = 10;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_DW.is_active_c7_flightControlSystem
                    section.data(2).logicalSrcIdx = 11;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_DW.is_active_c6_flightControlSystem
                    section.data(3).logicalSrcIdx = 12;
                    section.data(3).dtTransOffset = 2;

                    ;% flightControlSystem_DW.is_active_c5_flightControlSystem
                    section.data(4).logicalSrcIdx = 13;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% flightControlSystem_DW.RateTransition_3_Buffer0
                    section.data(1).logicalSrcIdx = 14;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_DW.doneDoubleBufferReInit
                    section.data(2).logicalSrcIdx = 16;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_DW.doneDoubleBufferReInit_l
                    section.data(3).logicalSrcIdx = 17;
                    section.data(3).dtTransOffset = 2;

                    ;% flightControlSystem_DW.doneDoubleBufferReInit_g
                    section.data(4).logicalSrcIdx = 18;
                    section.data(4).dtTransOffset = 3;

                    ;% flightControlSystem_DW.doneDoubleBufferReInit_c
                    section.data(5).logicalSrcIdx = 19;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_DW.FlightControlSystem.Memory1_PreviousInput
                    section.data(1).logicalSrcIdx = 20;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% flightControlSystem_DW.FlightControlSystem.Scope1_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 22;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_DW.FlightControlSystem.Scope_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 23;
                    section.data(2).dtTransOffset = 5;

                    ;% flightControlSystem_DW.FlightControlSystem.Scope2_PWORK.LoggedData
                    section.data(3).logicalSrcIdx = 24;
                    section.data(3).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_DW.FlightControlSystem.UnitDelay_DSTATE
                    section.data(1).logicalSrcIdx = 25;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% flightControlSystem_DW.FlightControlSystem.is_c4_flightControlSystem
                    section.data(1).logicalSrcIdx = 30;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_DW.FlightControlSystem.is_c2_flightControlSystem
                    section.data(2).logicalSrcIdx = 31;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_DW.FlightControlSystem.is_c1_flightControlSystem
                    section.data(3).logicalSrcIdx = 32;
                    section.data(3).dtTransOffset = 2;

                    ;% flightControlSystem_DW.FlightControlSystem.is_c3_flightControlSystem
                    section.data(4).logicalSrcIdx = 33;
                    section.data(4).dtTransOffset = 3;

                    ;% flightControlSystem_DW.FlightControlSystem.is_Takeoff
                    section.data(5).logicalSrcIdx = 34;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            dworkMap.sections(9) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% flightControlSystem_DW.FlightControlSystem.temporalCounter_i1
                    section.data(1).logicalSrcIdx = 36;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_DW.FlightControlSystem.temporalCounter_i1_d
                    section.data(2).logicalSrcIdx = 37;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_DW.FlightControlSystem.temporalCounter_i1_p
                    section.data(3).logicalSrcIdx = 38;
                    section.data(3).dtTransOffset = 2;

                    ;% flightControlSystem_DW.FlightControlSystem.temporalCounter_i1_pu
                    section.data(4).logicalSrcIdx = 39;
                    section.data(4).dtTransOffset = 3;

                    ;% flightControlSystem_DW.FlightControlSystem.temporalCounter_i2
                    section.data(5).logicalSrcIdx = 40;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            dworkMap.sections(10) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% flightControlSystem_DW.FlightControlSystem.is_active_c4_flightControlSystem
                    section.data(1).logicalSrcIdx = 41;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_DW.FlightControlSystem.is_active_c2_flightControlSystem
                    section.data(2).logicalSrcIdx = 42;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_DW.FlightControlSystem.is_active_c1_flightControlSystem
                    section.data(3).logicalSrcIdx = 43;
                    section.data(3).dtTransOffset = 2;

                    ;% flightControlSystem_DW.FlightControlSystem.is_active_c3_flightControlSystem
                    section.data(4).logicalSrcIdx = 44;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            dworkMap.sections(11) = section;
            clear section


            ;%
            ;% Non-auto Data (dwork)
            ;%


        ;%
        ;% Add final counts to struct.
        ;%
        dworkMap.nTotData = nTotData;



    ;%
    ;% Add individual maps to base struct.
    ;%

    targMap.paramMap  = paramMap;
    targMap.signalMap = sigMap;
    targMap.dworkMap  = dworkMap;

    ;%
    ;% Add checksums to base struct.
    ;%


    targMap.checksum0 = 1750311811;
    targMap.checksum1 = 3089197967;
    targMap.checksum2 = 4146967742;
    targMap.checksum3 = 3666445511;

