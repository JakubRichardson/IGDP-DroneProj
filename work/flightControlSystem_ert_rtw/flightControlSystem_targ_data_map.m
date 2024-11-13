    function targMap = targDataMap(),

    ;%***********************
    ;% Create Parameter Map *
    ;%***********************
    
        nTotData      = 0; %add to this count as we go
        nTotSects     = 12;
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
            section.nData     = 3;
            section.data(3)  = dumData; %prealloc

                    ;% flightControlSystem_P.CompareToConstant2_const
                    section.data(1).logicalSrcIdx = 2;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_P.RateTransition_1_InitialCondition
                    section.data(2).logicalSrcIdx = 3;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_P.RateTransition_2_InitialCondition
                    section.data(3).logicalSrcIdx = 4;
                    section.data(3).dtTransOffset = 2;

            nTotData = nTotData + section.nData;
            paramMap.sections(1) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% flightControlSystem_P.FlightControlSystem.CompareToConstant_const
                    section.data(1).logicalSrcIdx = 5;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_P.FlightControlSystem.CompareToConstant1_const
                    section.data(2).logicalSrcIdx = 6;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_P.FlightControlSystem.CompareToConstant2_const
                    section.data(3).logicalSrcIdx = 7;
                    section.data(3).dtTransOffset = 2;

                    ;% flightControlSystem_P.FlightControlSystem.CompareToConstant6_const
                    section.data(4).logicalSrcIdx = 8;
                    section.data(4).dtTransOffset = 3;

                    ;% flightControlSystem_P.FlightControlSystem.CompareToConstant3_const
                    section.data(5).logicalSrcIdx = 9;
                    section.data(5).dtTransOffset = 4;

                    ;% flightControlSystem_P.FlightControlSystem.CompareToConstant5_const
                    section.data(6).logicalSrcIdx = 10;
                    section.data(6).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            paramMap.sections(2) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_P.FlightControlSystem.Memory_InitialCondition
                    section.data(1).logicalSrcIdx = 11;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(3) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_P.FlightControlSystem.landingOverrideLimit_Value
                    section.data(1).logicalSrcIdx = 12;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(4) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% flightControlSystem_P.FlightControlSystem.Constant3_Value
                    section.data(1).logicalSrcIdx = 13;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_P.FlightControlSystem.Gain2_Gain
                    section.data(2).logicalSrcIdx = 14;
                    section.data(2).dtTransOffset = 3;

                    ;% flightControlSystem_P.FlightControlSystem.Gain1_Gain
                    section.data(3).logicalSrcIdx = 15;
                    section.data(3).dtTransOffset = 4;

                    ;% flightControlSystem_P.FlightControlSystem.Constant2_Value
                    section.data(4).logicalSrcIdx = 16;
                    section.data(4).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            paramMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_P.FlightControlSystem.Constant1_Value
                    section.data(1).logicalSrcIdx = 17;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(6) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_P.FlightControlSystem.Merge_InitialOutput
                    section.data(1).logicalSrcIdx = 18;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(7) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_P.FlightControlSystem.Normalcondition.Constant_Value
                    section.data(1).logicalSrcIdx = 19;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(8) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_P.FlightControlSystem.estimatorOpticalflowerror.Constant_Value
                    section.data(1).logicalSrcIdx = 20;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(9) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_P.FlightControlSystem.Geofencingerror.Constant_Value
                    section.data(1).logicalSrcIdx = 21;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            paramMap.sections(10) = section;
            clear section


            ;%
            ;% Non-auto Data (parameter)
            ;%

                        ;% Sensors
                        section.nData = 1;
                        section.data(1).logicalSrcIdx = 0;
                        section.data(1).dtTransOffset = 0;

                        nTotData = nTotData + section.nData;
                        paramMap.sections(11) = section;
                        clear section


                        ;% enableLanding
                        section.nData = 1;
                        section.data(1).logicalSrcIdx = 1;
                        section.data(1).dtTransOffset = 0;

                        nTotData = nTotData + section.nData;
                        paramMap.sections(12) = section;
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
            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% flightControlSystem_B.dy
                    section.data(1).logicalSrcIdx = 0;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_B.dx
                    section.data(2).logicalSrcIdx = 1;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_B.CastToDouble
                    section.data(3).logicalSrcIdx = 2;
                    section.data(3).dtTransOffset = 2;

                    ;% flightControlSystem_B.deltaX
                    section.data(4).logicalSrcIdx = 3;
                    section.data(4).dtTransOffset = 3;

                    ;% flightControlSystem_B.deltaY
                    section.data(5).logicalSrcIdx = 4;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            sigMap.sections(1) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_B.Submatrix
                    section.data(1).logicalSrcIdx = 5;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            sigMap.sections(2) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% flightControlSystem_B.Compare
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_B.BW
                    section.data(2).logicalSrcIdx = 7;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            sigMap.sections(3) = section;
            clear section

            section.nData     = 6;
            section.data(6)  = dumData; %prealloc

                    ;% flightControlSystem_B.FlightControlSystem.Grabber
                    section.data(1).logicalSrcIdx = 8;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_B.FlightControlSystem.x_g
                    section.data(2).logicalSrcIdx = 18;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_B.FlightControlSystem.y_b
                    section.data(3).logicalSrcIdx = 19;
                    section.data(3).dtTransOffset = 2;

                    ;% flightControlSystem_B.FlightControlSystem.z_g
                    section.data(4).logicalSrcIdx = 20;
                    section.data(4).dtTransOffset = 3;

                    ;% flightControlSystem_B.FlightControlSystem.grabber_c
                    section.data(5).logicalSrcIdx = 21;
                    section.data(5).dtTransOffset = 4;

                    ;% flightControlSystem_B.FlightControlSystem.takeoff_flag
                    section.data(6).logicalSrcIdx = 22;
                    section.data(6).dtTransOffset = 5;

            nTotData = nTotData + section.nData;
            sigMap.sections(4) = section;
            clear section

            section.nData     = 9;
            section.data(9)  = dumData; %prealloc

                    ;% flightControlSystem_B.FlightControlSystem.x_c
                    section.data(1).logicalSrcIdx = 23;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_B.FlightControlSystem.y_n
                    section.data(2).logicalSrcIdx = 24;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_B.FlightControlSystem.z_p
                    section.data(3).logicalSrcIdx = 25;
                    section.data(3).dtTransOffset = 2;

                    ;% flightControlSystem_B.FlightControlSystem.x_cd
                    section.data(4).logicalSrcIdx = 26;
                    section.data(4).dtTransOffset = 3;

                    ;% flightControlSystem_B.FlightControlSystem.y_nb
                    section.data(5).logicalSrcIdx = 27;
                    section.data(5).dtTransOffset = 4;

                    ;% flightControlSystem_B.FlightControlSystem.z_p1
                    section.data(6).logicalSrcIdx = 28;
                    section.data(6).dtTransOffset = 5;

                    ;% flightControlSystem_B.FlightControlSystem.altitude
                    section.data(7).logicalSrcIdx = 29;
                    section.data(7).dtTransOffset = 6;

                    ;% flightControlSystem_B.FlightControlSystem.pressure
                    section.data(8).logicalSrcIdx = 30;
                    section.data(8).dtTransOffset = 7;

                    ;% flightControlSystem_B.FlightControlSystem.controller_o2
                    section.data(9).logicalSrcIdx = 31;
                    section.data(9).dtTransOffset = 8;

            nTotData = nTotData + section.nData;
            sigMap.sections(5) = section;
            clear section

            section.nData     = 27;
            section.data(27)  = dumData; %prealloc

                    ;% flightControlSystem_B.FlightControlSystem.Logging.X
                    section.data(1).logicalSrcIdx = 32;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_B.FlightControlSystem.Logging.Y
                    section.data(2).logicalSrcIdx = 33;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_B.FlightControlSystem.Logging.Z
                    section.data(3).logicalSrcIdx = 34;
                    section.data(3).dtTransOffset = 2;

                    ;% flightControlSystem_B.FlightControlSystem.Logging.yaw
                    section.data(4).logicalSrcIdx = 35;
                    section.data(4).dtTransOffset = 3;

                    ;% flightControlSystem_B.FlightControlSystem.Logging.pitch
                    section.data(5).logicalSrcIdx = 36;
                    section.data(5).dtTransOffset = 4;

                    ;% flightControlSystem_B.FlightControlSystem.Logging.roll
                    section.data(6).logicalSrcIdx = 37;
                    section.data(6).dtTransOffset = 5;

                    ;% flightControlSystem_B.FlightControlSystem.Logging.dx
                    section.data(7).logicalSrcIdx = 38;
                    section.data(7).dtTransOffset = 6;

                    ;% flightControlSystem_B.FlightControlSystem.Logging.dy
                    section.data(8).logicalSrcIdx = 39;
                    section.data(8).dtTransOffset = 7;

                    ;% flightControlSystem_B.FlightControlSystem.Logging.dz
                    section.data(9).logicalSrcIdx = 40;
                    section.data(9).dtTransOffset = 8;

                    ;% flightControlSystem_B.FlightControlSystem.Logging.p
                    section.data(10).logicalSrcIdx = 41;
                    section.data(10).dtTransOffset = 9;

                    ;% flightControlSystem_B.FlightControlSystem.Logging.q
                    section.data(11).logicalSrcIdx = 42;
                    section.data(11).dtTransOffset = 10;

                    ;% flightControlSystem_B.FlightControlSystem.Logging.r
                    section.data(12).logicalSrcIdx = 43;
                    section.data(12).dtTransOffset = 11;

                    ;% flightControlSystem_B.FlightControlSystem.Logging.TmpSignalConversionAtToWorkspace2Inport1
                    section.data(13).logicalSrcIdx = 44;
                    section.data(13).dtTransOffset = 12;

                    ;% flightControlSystem_B.FlightControlSystem.Logging.DataTypeConversion1
                    section.data(14).logicalSrcIdx = 45;
                    section.data(14).dtTransOffset = 24;

                    ;% flightControlSystem_B.FlightControlSystem.Logging.DataTypeConversion2
                    section.data(15).logicalSrcIdx = 46;
                    section.data(15).dtTransOffset = 25;

                    ;% flightControlSystem_B.FlightControlSystem.Logging.TmpSignalConversionAtToWorkspace6Inport1
                    section.data(16).logicalSrcIdx = 47;
                    section.data(16).dtTransOffset = 26;

                    ;% flightControlSystem_B.FlightControlSystem.Logging.DataTypeConversion3
                    section.data(17).logicalSrcIdx = 48;
                    section.data(17).dtTransOffset = 36;

                    ;% flightControlSystem_B.FlightControlSystem.Logging.pos_ref
                    section.data(18).logicalSrcIdx = 49;
                    section.data(18).dtTransOffset = 37;

                    ;% flightControlSystem_B.FlightControlSystem.Logging.DataTypeConversion7
                    section.data(19).logicalSrcIdx = 50;
                    section.data(19).dtTransOffset = 40;

                    ;% flightControlSystem_B.FlightControlSystem.Logging.orient_ref
                    section.data(20).logicalSrcIdx = 51;
                    section.data(20).dtTransOffset = 41;

                    ;% flightControlSystem_B.FlightControlSystem.Logging.DataTypeConversion9
                    section.data(21).logicalSrcIdx = 52;
                    section.data(21).dtTransOffset = 44;

                    ;% flightControlSystem_B.FlightControlSystem.Logging.TmpSignalConversionAtToWorkspace3Inport1
                    section.data(22).logicalSrcIdx = 53;
                    section.data(22).dtTransOffset = 45;

                    ;% flightControlSystem_B.FlightControlSystem.Logging.DataTypeConversion11
                    section.data(23).logicalSrcIdx = 54;
                    section.data(23).dtTransOffset = 54;

                    ;% flightControlSystem_B.FlightControlSystem.Logging.opticalFlow_data
                    section.data(24).logicalSrcIdx = 55;
                    section.data(24).dtTransOffset = 55;

                    ;% flightControlSystem_B.FlightControlSystem.Logging.posVIS_data
                    section.data(25).logicalSrcIdx = 56;
                    section.data(25).dtTransOffset = 58;

                    ;% flightControlSystem_B.FlightControlSystem.Logging.TmpSignalConversionAtToWorkspace4Inport1
                    section.data(26).logicalSrcIdx = 57;
                    section.data(26).dtTransOffset = 62;

                    ;% flightControlSystem_B.FlightControlSystem.Logging.SensorCalibration
                    section.data(27).logicalSrcIdx = 58;
                    section.data(27).dtTransOffset = 70;

            nTotData = nTotData + section.nData;
            sigMap.sections(6) = section;
            clear section


            ;%
            ;% Non-auto Data (signal)
            ;%

                        ;% motors_outport
                        section.nData = 1;
                        section.data(1).logicalSrcIdx = 86;
                        section.data(1).dtTransOffset = 0;

                        nTotData = nTotData + section.nData;
                        sigMap.sections(7) = section;
                        clear section


                        ;% flag_outport
                        section.nData = 1;
                        section.data(1).logicalSrcIdx = 87;
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
        nTotSects     = 13;
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
                    section.data(1).logicalSrcIdx = 6;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_DW.RateTransition_2_ActiveBufIdx
                    section.data(2).logicalSrcIdx = 7;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(3) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% flightControlSystem_DW.is_active_c6_flightControlSystem
                    section.data(1).logicalSrcIdx = 8;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_DW.is_active_c5_flightControlSystem
                    section.data(2).logicalSrcIdx = 9;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(4) = section;
            clear section

            section.nData     = 2;
            section.data(2)  = dumData; %prealloc

                    ;% flightControlSystem_DW.doneDoubleBufferReInit
                    section.data(1).logicalSrcIdx = 11;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_DW.doneDoubleBufferReInit_c
                    section.data(2).logicalSrcIdx = 12;
                    section.data(2).dtTransOffset = 1;

            nTotData = nTotData + section.nData;
            dworkMap.sections(5) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_DW.FlightControlSystem.Scope_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 14;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(6) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% flightControlSystem_DW.FlightControlSystem.is_c4_flightControlSystem
                    section.data(1).logicalSrcIdx = 19;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_DW.FlightControlSystem.is_c2_flightControlSystem
                    section.data(2).logicalSrcIdx = 20;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_DW.FlightControlSystem.is_c1_flightControlSystem
                    section.data(3).logicalSrcIdx = 21;
                    section.data(3).dtTransOffset = 2;

                    ;% flightControlSystem_DW.FlightControlSystem.is_c3_flightControlSystem
                    section.data(4).logicalSrcIdx = 22;
                    section.data(4).dtTransOffset = 3;

                    ;% flightControlSystem_DW.FlightControlSystem.is_Takeoff
                    section.data(5).logicalSrcIdx = 23;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            dworkMap.sections(7) = section;
            clear section

            section.nData     = 5;
            section.data(5)  = dumData; %prealloc

                    ;% flightControlSystem_DW.FlightControlSystem.temporalCounter_i1
                    section.data(1).logicalSrcIdx = 25;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_DW.FlightControlSystem.temporalCounter_i1_d
                    section.data(2).logicalSrcIdx = 26;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_DW.FlightControlSystem.temporalCounter_i1_p
                    section.data(3).logicalSrcIdx = 27;
                    section.data(3).dtTransOffset = 2;

                    ;% flightControlSystem_DW.FlightControlSystem.temporalCounter_i1_g
                    section.data(4).logicalSrcIdx = 28;
                    section.data(4).dtTransOffset = 3;

                    ;% flightControlSystem_DW.FlightControlSystem.temporalCounter_i2
                    section.data(5).logicalSrcIdx = 29;
                    section.data(5).dtTransOffset = 4;

            nTotData = nTotData + section.nData;
            dworkMap.sections(8) = section;
            clear section

            section.nData     = 4;
            section.data(4)  = dumData; %prealloc

                    ;% flightControlSystem_DW.FlightControlSystem.is_active_c4_flightControlSystem
                    section.data(1).logicalSrcIdx = 30;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_DW.FlightControlSystem.is_active_c2_flightControlSystem
                    section.data(2).logicalSrcIdx = 31;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_DW.FlightControlSystem.is_active_c1_flightControlSystem
                    section.data(3).logicalSrcIdx = 32;
                    section.data(3).dtTransOffset = 2;

                    ;% flightControlSystem_DW.FlightControlSystem.is_active_c3_flightControlSystem
                    section.data(4).logicalSrcIdx = 33;
                    section.data(4).dtTransOffset = 3;

            nTotData = nTotData + section.nData;
            dworkMap.sections(9) = section;
            clear section

            section.nData     = 7;
            section.data(7)  = dumData; %prealloc

                    ;% flightControlSystem_DW.FlightControlSystem.Logging.ToWorkspace2_PWORK.LoggedData
                    section.data(1).logicalSrcIdx = 35;
                    section.data(1).dtTransOffset = 0;

                    ;% flightControlSystem_DW.FlightControlSystem.Logging.ToWorkspace6_PWORK.LoggedData
                    section.data(2).logicalSrcIdx = 36;
                    section.data(2).dtTransOffset = 1;

                    ;% flightControlSystem_DW.FlightControlSystem.Logging.ToWorkspace3_PWORK.LoggedData
                    section.data(3).logicalSrcIdx = 37;
                    section.data(3).dtTransOffset = 2;

                    ;% flightControlSystem_DW.FlightControlSystem.Logging.ToWorkspace4_PWORK.LoggedData
                    section.data(4).logicalSrcIdx = 38;
                    section.data(4).dtTransOffset = 3;

                    ;% flightControlSystem_DW.FlightControlSystem.Logging.ToWorkspace5_PWORK.LoggedData
                    section.data(5).logicalSrcIdx = 39;
                    section.data(5).dtTransOffset = 4;

                    ;% flightControlSystem_DW.FlightControlSystem.Logging.ToWorkspace_PWORK.LoggedData
                    section.data(6).logicalSrcIdx = 40;
                    section.data(6).dtTransOffset = 5;

                    ;% flightControlSystem_DW.FlightControlSystem.Logging.ToWorkspace1_PWORK.LoggedData
                    section.data(7).logicalSrcIdx = 41;
                    section.data(7).dtTransOffset = 6;

            nTotData = nTotData + section.nData;
            dworkMap.sections(10) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_DW.FlightControlSystem.Normalcondition.Geofencingerror_SubsysRanBC
                    section.data(1).logicalSrcIdx = 42;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(11) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_DW.FlightControlSystem.estimatorOpticalflowerror.Geofencingerror_SubsysRanBC
                    section.data(1).logicalSrcIdx = 43;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(12) = section;
            clear section

            section.nData     = 1;
            section.data(1)  = dumData; %prealloc

                    ;% flightControlSystem_DW.FlightControlSystem.Geofencingerror.Geofencingerror_SubsysRanBC
                    section.data(1).logicalSrcIdx = 44;
                    section.data(1).dtTransOffset = 0;

            nTotData = nTotData + section.nData;
            dworkMap.sections(13) = section;
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


    targMap.checksum0 = 1191579305;
    targMap.checksum1 = 3338200727;
    targMap.checksum2 = 1210126136;
    targMap.checksum3 = 858923583;

